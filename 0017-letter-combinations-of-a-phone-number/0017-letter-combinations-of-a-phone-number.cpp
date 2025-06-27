class Solution {
public:
    void func(int ind, string digits, string s, vector<string>& ans, string combos[]){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }
        int num = digits[ind] - '0';
        for(int i=0; i<combos[num].size(); i++){
            func(ind+1, digits, s+combos[num][i], ans, combos);
        }
    }
    vector<string> letterCombinations(string digits) {
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans; 
        string s = ""; 
        
        if(digits == "") return {};
        func(0, digits, s, ans, combos);
        return ans; 
    }
};