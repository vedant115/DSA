class Solution {
public:
    void genFunc(int open, int close, string s, vector<string>& res, int n){
        if(open == close && open + close == 2*n) res.push_back(s);

        if(open < n) genFunc(open+1, close, s+'(', res, n);
        if(close < open) genFunc(open, close+1, s+')', res, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        genFunc(0, 0, "", res, n);
        return res;
    }
};