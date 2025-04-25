class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long n = nums.size();
        long long prefixCnt = 0;
        unordered_map<long long, long long> cntFreq;
        cntFreq[0] = 1;
        long long res = 0;
        for(int i=0; i<n; i++){
            if(nums[i] % modulo == k) prefixCnt++;
            prefixCnt %= modulo;
            long long reqCnt = (prefixCnt - k + modulo) % modulo;
            if(cntFreq.count(reqCnt)){
                res += cntFreq[reqCnt];
            }
            cntFreq[prefixCnt]++;
        }
        return res;
    }
};