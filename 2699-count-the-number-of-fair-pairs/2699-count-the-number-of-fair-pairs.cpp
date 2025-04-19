class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long res = 0;

        for (int i = 0; i < n; ++i) {
            long long minPair = (long long)lower - nums[i];
            long long maxPair = (long long)upper - nums[i];

            auto left = lower_bound(nums.begin() + i + 1, nums.end(), minPair);
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), maxPair);

            res += right - left;
        }

        return res;
    }
};
