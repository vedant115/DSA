class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the median
        auto mid = nums.begin() + n / 2;
        nth_element(nums.begin(), mid, nums.end());
        int median = *mid;

        // Virtual indexing lambda
        auto index = [n](int i) { return (1 + 2 * i) % (n | 1); };

        // 3-way partition (Dutch National Flag)
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (nums[index(j)] > median) {
                swap(nums[index(i)], nums[index(j)]);
                i++; j++;
            } else if (nums[index(j)] < median) {
                swap(nums[index(j)], nums[index(k)]);
                k--;
            } else {
                j++;
            }
        }
    }
};
