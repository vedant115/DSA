class Solution {
private:
    long long solve(int i, vector<vector<int>>& questions, vector<long long>& dp) {
        if (i >= questions.size()) return 0;
        if (dp[i] != -1) return dp[i];

        // Option 1: Skip the current question
        long long skip = solve(i + 1, questions, dp);

        // Option 2: Solve the current question
        long long solveCurrent = questions[i][0] + solve(i + questions[i][1] + 1, questions, dp);

        // Store the maximum of both choices
        return dp[i] = max(skip, solveCurrent);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(0, questions, dp);
    }
};
