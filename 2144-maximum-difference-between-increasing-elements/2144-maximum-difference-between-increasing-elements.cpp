class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minSoFar = nums[0], maxDiff = -1;
        for (int i = 1; i < nums.size(); ++i) {
            maxDiff = max(maxDiff, nums[i] - minSoFar);
            minSoFar = min(minSoFar, nums[i]);
        }
        return maxDiff == 0 ? -1 : maxDiff;
    }
};