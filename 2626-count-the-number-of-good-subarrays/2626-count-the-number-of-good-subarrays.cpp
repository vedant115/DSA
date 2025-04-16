class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        unordered_map<int, long long> freq;

        long long res = 0;
        long long pairs = 0;
        while(r < n){
            pairs += freq[nums[r]];
            freq[nums[r]]++;
            while (pairs >= k) {
                res += (n - r);
                freq[nums[l]]--;
                pairs -= freq[nums[l]];
                l++;
            }
            r++;
        }
        return res;
    }
};