class Solution {
private:
    int f(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (i == 0) return (amount % coins[i] == 0) ? 1 : 0;

        if (dp[i][amount] != -1) return dp[i][amount];

        int notpick = f(i - 1, amount, coins, dp);
        int pick = 0;
        if (coins[i] <= amount) {
            pick = f(i, amount - coins[i], coins, dp);
        }

        return dp[i][amount] = pick + notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return f(n - 1, amount, coins, dp);
    }
};