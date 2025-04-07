class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for(int num : nums) total += num;
        if(total%2 == 1) return false;
        int reqSum = total/2;

        vector<vector<bool>> dp(nums.size()+1, vector<bool>((total/2)+1, false));
        for(int i=0; i<=n; i++){
            dp[i][0] = true;
        }
        for(int i=1; i<=n; i++){
            for(int sum=0; sum<=reqSum; sum++){
                if(sum >= nums[i-1]){
                    dp[i][sum] = dp[i-1][sum] || dp[i-1][sum - nums[i-1]];
                } else {
                    dp[i][sum] = dp[i-1][sum];
                }
            }
        }
        
        return dp[n][reqSum];
    }
};