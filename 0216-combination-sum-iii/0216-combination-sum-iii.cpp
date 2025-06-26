class Solution {
public:
    void backtrack(int num, int k, int n, vector<int>& path, vector<vector<int>>& result) {
        // Base case
        if (k == 0 && n == 0) {
            result.push_back(path);
            return;
        }
        if (num > 9 || k < 0 || n < 0) return;

        // Include current number
        path.push_back(num);
        backtrack(num + 1, k - 1, n - num, path, result);
        path.pop_back();  // backtrack

        // Skip current number
        backtrack(num + 1, k, n, path, result);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(1, k, n, path, result);
        return result;
    }
};
