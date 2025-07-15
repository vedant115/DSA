class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, res = 0;
        unordered_map<char, int> freq;
        while(r < s.size()){
            freq[s[r]]++;
            while(freq['a'] >= 1 && freq['b'] >= 1 && freq['c'] >= 1){
                if(freq[s[l]] > 1){
                    freq[s[l]]--;
                    l++;  
                }
                else{
                    break;
                }
                if(freq['a'] == 1 && freq['b'] == 1 && freq['c'] == 1){
                    break;
                }
            }
            if(freq['a'] >= 1 && freq['b'] >= 1 && freq['c'] >= 1){
                res += (l + 1);
            }
            r++;
        }
        return res;
    }
};