class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total & 1) return false;
        int reqSum = total / 2;

        // dp[s] == true if we can make sum 's' using some of the numbers seen so far
        vector<bool> dp(reqSum+1, false);
        dp[0] = true;  // zero sum is always possible (take no elements)

        for (int num : nums) {
            // iterate backwards so that each num is only used once
            for (int s = reqSum; s >= num; --s) {
                dp[s] = dp[s] || dp[s - num];
            }
        }

        return dp[reqSum];
    }
};