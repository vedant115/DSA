class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);
        int res = 0;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            lastSeen[ch - 'a'] = i;
            res += (min({lastSeen[0], lastSeen[1], lastSeen[2]}) + 1);
        }
        return res;
    }
};