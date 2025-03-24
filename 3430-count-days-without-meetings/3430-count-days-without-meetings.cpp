class Solution {
private:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), compare);
        int prev = 0;
        int res = 0;
        for(auto& arr : meetings){
            if(arr[0] > prev){
                res += (arr[0] - prev - 1);
            }
            prev = max(prev, arr[1]);
        }
        if(prev < days) res += (days - prev);
        return res;
    }
};