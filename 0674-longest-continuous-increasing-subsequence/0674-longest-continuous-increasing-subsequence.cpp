class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int start = 0, max_len = 1;

        for (int end = 1; end < n; end++) {
            if (nums[end] > nums[end - 1]) {
                // Extend the window
                max_len = max(max_len, end - start + 1);
            } else {
                // Reset the window start
                start = end;
            }
        }

        return max_len;
    }
};