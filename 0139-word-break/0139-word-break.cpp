class Solution {
private:
    int solve(int i, string& s, vector<string>& wordDict, vector<int>& dp){
        if(i == s.size()) return true;
        
        if(dp[i] != -1) return dp[i]==1;

        for(auto& word : wordDict){
            int wordLen = word.size();
            if(i+wordLen <= s.size()){
                if(s.substr(i, wordLen) == word){
                    if(solve(i+wordLen, s, wordDict, dp))
                        return dp[i] = 1;
                }
            }
        }
        return dp[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1, -1);
        return solve(0, s, wordDict, dp) == 1;
    }
};