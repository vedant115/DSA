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
        int freeDays = 0;
        int current_end = 0;
        
        for (auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            // If there is a gap before this meeting starts
            if (start > current_end + 1) {
                freeDays += (start - current_end - 1);
            }
            // Update current_end by merging overlapping intervals
            current_end = max(current_end, end);
        }
        // Count any free days after the last meeting until 'days'
        if (current_end < days) {
            freeDays += (days - current_end);
        }
        return freeDays;
    }
};