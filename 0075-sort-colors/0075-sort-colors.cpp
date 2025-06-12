class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)
            return;

        int l = 0, m = 0, r = n - 1;
        while (m <= r) {
            if (nums[m] == 0) {
                swap(nums[m], nums[l]);
                l++;
                m++;
            } else if (nums[m] == 1) {
                m++;
            } else {
                swap(nums[m], nums[r]);
                r--;
            }
        }
    }
};