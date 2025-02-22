class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        int prefixSum = 0, res = 0;
        map[0] = 1;
        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            res += map[prefixSum - k];
            map[prefixSum]++;
        }
        return res;
    }
};