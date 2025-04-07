class Solution {
private:
    bool solve(int i, int sum, vector<int>& nums, int reqSum, vector<vector<int>>& dp){
        if(i == nums.size()) return sum == reqSum;

        if(dp[i][sum] != -1) return dp[i][sum];

        int include = solve(i+1, sum+nums[i], nums, reqSum, dp);
        int exclude = solve(i+1, sum, nums, reqSum, dp);

        return dp[i][sum] = include || exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num : nums) total += num;
        if(total%2 == 1) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(total, -1));
        return solve(0, 0, nums, total/2, dp);
    }
};