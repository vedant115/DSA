class Solution {
private:
    string computeRLE(string s) {
        string ans = "";
        int i = 0;
        while (i < s.length()) {
            int count = 1;
            while (i + 1 < s.length() && s[i] == s[i + 1]) {
                i++;
                count++;
            }
            ans += to_string(count);
            ans += s[i];
            i++;
        }
        return ans;
    }
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string temp = countAndSay(n - 1);
        return computeRLE(temp);
    }
};