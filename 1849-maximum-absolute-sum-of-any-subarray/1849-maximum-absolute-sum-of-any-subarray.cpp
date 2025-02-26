class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int minSum = 0, maxSum = 0;
        int currSum = 0;

        for(int i=0; i<n; i++){
            currSum += nums[i];
            minSum = min(minSum, currSum);
            maxSum = max(maxSum, currSum);
        }
        return maxSum-minSum;
    }
};