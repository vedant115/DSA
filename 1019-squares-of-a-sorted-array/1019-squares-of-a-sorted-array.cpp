class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int pos = n - 1;
        vector<int> result(n);

        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                result[pos] = nums[l] * nums[l];
                l++;
            } else {
                result[pos] = nums[r] * nums[r];
                r--;
            }
            pos--;
        }
        return result;
    }
};
