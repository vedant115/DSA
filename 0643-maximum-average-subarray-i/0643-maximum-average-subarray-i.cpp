class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        cout << n;
        if(k == n) return (double)accumulate(nums.begin(), nums.end(), 0)/n;

        int left = 0, right = 0;
        double currSum = 0;
        double res = INT_MIN;
        while(right < n){
            currSum += nums[right];
            if(right-left+1 > k){ 
                currSum -= nums[left];
                left++;
            }
            if(right-left+1 == k){
                res = max(res, currSum/k);
            }
            right++;
        }
        return res;
    }
};