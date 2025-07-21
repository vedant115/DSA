class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> st; // Stack to maintain increasing order
        
        // Traverse each digit in the number
        for (char digit : nums) {
            // Remove larger digits if k > 0
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit); // Add current digit
        }
        
        // Remove remaining digits from the end
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        
        // Build the result from the stack
        string result = "";
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        
        // Remove leading zeroes
        int i = 0;
        while (i < result.size() && result[i] == '0') i++;
        result = result.substr(i);
        
        return result.empty() ? "0" : result;
    }
};
