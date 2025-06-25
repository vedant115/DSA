class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        int res = 0;
        vector<bool> dp(n, true);
        dp[0] = false;
        dp[1] = false;
        for(int i=2; i<n; i++){
            if(dp[i]){
                res++;
                for(int j=i*2; j<n; j+=i){
                    dp[j] = false;
                }
            }
        }
        return res;
    }
};