class Solution {
public:
    bool isPalindrome(string str, int s, int e){
        while(s<=e){
            if(str[s++]!=str[e--])
                return false;
        }
        return true;
    }
    void func(int ind, string s, vector<string>& list, vector<vector<string>>& ans){
        if(ind == s.size()){
            ans.push_back(list);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                list.push_back(s.substr(ind, i-ind+1));
                func(i+1, s, list, ans);
                list.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> list;
        func(0, s, list, ans);
        return ans;
    }
};