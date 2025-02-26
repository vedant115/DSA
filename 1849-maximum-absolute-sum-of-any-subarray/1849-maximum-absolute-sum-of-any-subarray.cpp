class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int res, minSum = INT_MAX, maxSum = INT_MIN;
        int currMinSum = 0, currMaxSum = 0;

        for(int i=0; i<n; i++){
            currMinSum += nums[i];
            minSum = min(minSum, currMinSum);
            if(currMinSum > 0) currMinSum = 0;

            currMaxSum += nums[i];
            maxSum = max(maxSum, currMaxSum);
            if(currMaxSum < 0) currMaxSum = 0;

            res = max(abs(minSum), maxSum);
        }
        return res;
    }
};