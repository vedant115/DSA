class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, res = 0;
        for(char ch : s){
            if(ch == '(') open++;
            else close++;

            if(open == close) res = max(res, open*2);
            else if(close > open){
                open = 0;
                close = 0;
            }
        }
        open = 0, close = 0;
        for(int i=s.size()-1; i>=0; i--){
            char ch = s[i];
            if(ch == '(') open++;
            else close++;

            if(open == close) res = max(res, open*2);
            else if(close < open){
                open = 0;
                close = 0;
            }
        }
        return res;
    }
};