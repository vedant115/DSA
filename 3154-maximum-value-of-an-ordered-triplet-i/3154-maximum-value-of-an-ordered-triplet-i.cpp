class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        
        vector<int> maxI(n, 0), maxK(n, 0);
        for(int i=1; i<n-1; i++){
            maxI[i] = max(maxI[i-1], nums[i-1]);
            maxK[n-i-1] = max(maxK[n-i], nums[n-i]);
        }

        for(int j=1; j<n-1; j++){
            res = max(res, ((long long)maxI[j]-nums[j])*maxK[j]);
        }
        
        return res;
    }
};