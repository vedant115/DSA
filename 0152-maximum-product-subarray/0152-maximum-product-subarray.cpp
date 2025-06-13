class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxProd = nums[0];
        int maxSoFar = nums[0];
        int minSoFar = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            // As num is negative maxSoFar will be minSoFar*num
            // and minSoFar will be maxSoFar*num
            if (nums[i] < 0) swap(maxSoFar, minSoFar);

            maxSoFar = max(nums[i], nums[i] * maxSoFar);
            minSoFar = min(nums[i], nums[i] * minSoFar);

            maxProd = max(maxProd, maxSoFar);
        }

        return maxProd;
    }
};
