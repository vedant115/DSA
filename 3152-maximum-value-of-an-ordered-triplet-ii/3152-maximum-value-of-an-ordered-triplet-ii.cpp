class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0, maxI = 0, maxDiff = 0;
        for(int k=0; k<nums.size(); k++){
            res = max(res, maxDiff*nums[k]);
            maxDiff = max(maxDiff, maxI-nums[k]);
            maxI = max(maxI, (long long)nums[k]);
        }
        return res;
    }
};