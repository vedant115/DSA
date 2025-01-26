class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(3, vector<int>(2, 0)), curr(3, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 2; k++) {
                curr[k][0] = max(after[k][0], after[k][1] - prices[i]);
                curr[k][1] = max(after[k][1], after[k - 1][0] + prices[i]);
            }
            after = curr;
        }

        return after[2][0];
    }
};