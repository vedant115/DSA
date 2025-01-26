class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, 0)));

        for(int i=n-1; i>=0; i--){
            for(int k=1; k<3; k++){
                dp[i][k][0] = max(dp[i+1][k][0], dp[i+1][k][1] - prices[i]);
                dp[i][k][1] = max(dp[i+1][k][1], dp[i+1][k-1][0] + prices[i]);
            }
        }

        return dp[0][2][0];
    }
};