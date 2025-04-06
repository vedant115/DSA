class Solution {
private:
    int helper(int i, vector<int>& nums, vector<int>& dp, vector<int>& prev) {
        if (dp[i] != -1) return dp[i];
        int maxLen = 1, bestPrev = -1;
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0) {
                int len = helper(j, nums, dp, prev) + 1;
                if (len > maxLen) {
                    maxLen = len;
                    bestPrev = j;
                }
            }
        }
        dp[i] = maxLen;
        prev[i] = bestPrev;
        return dp[i];
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, -1), prev(n, -1);
        int maxLen = 0, lastIndex = -1;

        for (int i = 0; i < n; ++i) {
            int len = helper(i, nums, dp, prev);
            if (len > maxLen) {
                maxLen = len;
                lastIndex = i;
            }
        }

        vector<int> result;
        while (lastIndex != -1) {
            result.push_back(nums[lastIndex]);
            lastIndex = prev[lastIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};