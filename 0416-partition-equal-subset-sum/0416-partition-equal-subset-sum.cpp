class Solution {
private:
    bool solve(int i, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(i == nums.size()) return false;

        if(dp[i][sum] != -1) return dp[i][sum];

        bool include = false;
        if(sum >= nums[i])
            include = solve(i+1, sum-nums[i], nums, dp);

        bool exclude = solve(i+1, sum, nums, dp);

        return dp[i][sum] = include || exclude;
    }

public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num : nums) total += num;
        if(total%2 == 1) return false;
        vector<vector<int>> dp(nums.size(), vector<int>((total/2)+1, -1));
        return solve(0, total/2, nums, dp);
    }
};