class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string s = "1";
        string ans = "";
        for(int ch=2; ch<=n; ch++){
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
            s = ans;
            ans = "";
        }
        return s;
    }
};