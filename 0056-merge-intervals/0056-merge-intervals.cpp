class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end()); // Sort by start

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            auto &last = merged.back();
            auto &cur = intervals[i];

            if (cur[0] <= last[1]) {
                // Overlap → merge
                last[1] = max(last[1], cur[1]);
            } else {
                // No overlap → add fresh
                merged.push_back(cur);
            }
        }
        return merged;
    }
};