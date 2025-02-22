class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;

        for(int num : st) {
            if(!st.count(num - 1)) {
                int x = num, cnt = 1;
                while(st.count(x + 1)) {
                    x++;
                    cnt++;
                }
                res = max(res, cnt);
            }
        }

        return res;
    }
};