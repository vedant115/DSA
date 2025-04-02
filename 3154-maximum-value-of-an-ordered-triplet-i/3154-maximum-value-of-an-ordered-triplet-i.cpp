class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int maxPrefix = 0;
        for(int j=1; j<n-1; j++){
            maxPrefix = max(maxPrefix, nums[j-1]);
            for(int k=j+1; k<n; k++){
                long long value = ((long long)maxPrefix-nums[j])*nums[k];
                if(value > 0){
                    res = max(res, value);
                }
            }
        }
        
        return res;
    }
};