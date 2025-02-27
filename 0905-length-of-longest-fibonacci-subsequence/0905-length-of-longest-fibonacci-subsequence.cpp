class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;
        vector<vector<int>> dp(n, vector<int>(n, 2));

        for(int i=0; i<n; i++) mpp[arr[i]] = i;

        for(int k = 2; k<n; k++){
            for(int j=1; j<k; j++){
                int a = arr[k] - arr[j];
                if(mpp.find(a) != mpp.end() && mpp[a] < j){
                    dp[j][k] = dp[mpp[a]][j] + 1;
                }
            }
        }

        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                res = max(res, dp[i][j]);
            }
        }

        return res == 2 ? 0 : res;
    }
};