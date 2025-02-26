class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int res, minSum = INT_MAX, maxSum = INT_MIN;
        int sum1 = 0, sum2 = 0;
        for(int i=0; i<n; i++){
            sum1 += nums[i], sum2 += nums[i];

            minSum = min(minSum, sum1);
            if(sum1 > nums[i]){
                sum1 = nums[i];
            }

            maxSum = max(maxSum, sum2);
            if(sum2 < 0){
                sum2 = 0;
            }

            res = max(maxSum, abs(minSum));
        }
        return res;
    }
};