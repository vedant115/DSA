class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int sum = 0, minLen = INT_MAX;
        for(int end=0; end<n; end++){
            sum += nums[end];
            while(start < n && sum >= target){
                minLen = min(minLen, (end-start+1));
                sum -= nums[start];
                start++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};