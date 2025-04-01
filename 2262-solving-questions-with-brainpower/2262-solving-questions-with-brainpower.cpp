class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, -1);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            // Option 1: Skip the current question
            long long skip = dp[i+1];

            // Option 2: Solve the current question
            long long solveCurrent = questions[i][0];
            int next = i + questions[i][1] + 1;
            if(next <= n)
                solveCurrent += dp[next];

            // Store the maximum of both choices
            dp[i] = max(skip, solveCurrent);
        }
        return dp[0];
    }
};
