class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0; // Number of intervals to remove
        int end = intervals[0][1]; // End of last added interval

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                // Overlapping, remove this one (increase count)
                count++;
            } else {
                // No overlap, update end
                end = intervals[i][1];
            }
        }

        return count;
    }
};