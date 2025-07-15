class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, res = 0;
        unordered_map<char, int> freq;

        for (int r = 0; r < s.size(); ++r) {
            freq[s[r]]++;

            // Shrink the window while it contains all 3 characters
            while (freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0) {
                res += s.size() - r;  // all substrings from l to end that include r
                freq[s[l]]--;
                l++;
            }
        }
        return res;
    }
};
