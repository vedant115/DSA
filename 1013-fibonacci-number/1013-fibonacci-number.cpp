class Solution {
public:
    static vector<int> dp; 
    Solution() {
        if(dp.empty()){
            dp.resize(31, -1);
            dp[0] = 0;
            dp[1] = 1;
        }
    }
    int fib(int n) {
        if(n <= 1){
            return dp[n];
        }
        else if(dp[n] != -1){
            return dp[n];
        }
        else{
            return dp[n] = fib(n-1) + fib(n-2);
        }
    }
};
vector<int> Solution::dp;