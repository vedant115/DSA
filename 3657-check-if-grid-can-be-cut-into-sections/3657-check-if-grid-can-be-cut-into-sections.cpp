class Solution {
private:
    static bool compare(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

    bool check(vector<vector<int>>& intervals) {
        int count = 0;
        int prevEnd = 0;
        for (const auto& interval : intervals) {
            if (interval[0] >= prevEnd) {
                count++;
                prevEnd = interval[1];
            } else {
                prevEnd = max(prevEnd, interval[1]);
            }
        }
        return count >= 3;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> verticalIntervals;
        vector<vector<int>> horizontalIntervals;

        for (const auto& rect : rectangles) {
            verticalIntervals.push_back({rect[0], rect[2]});
            horizontalIntervals.push_back({rect[1], rect[3]});
        }

        sort(verticalIntervals.begin(), verticalIntervals.end(), compare);
        sort(horizontalIntervals.begin(), horizontalIntervals.end(), compare);

        return check(verticalIntervals) || check(horizontalIntervals);
    }
};