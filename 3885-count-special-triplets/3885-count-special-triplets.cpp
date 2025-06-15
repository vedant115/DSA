class Solution {
public:
    int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }

        unordered_map<int, int> leftMap;
        int ans = 0;
        for(int i=0; i<n; i++){
            int dobNum = 2*nums[i];
            int left = leftMap[dobNum];
            int right = (mp[dobNum] - left) ? mp[dobNum] - left : 0;
            if(dobNum == nums[i]) right--;

            ans = (ans + (1LL * left * right) % MOD) % MOD;
            leftMap[nums[i]]++;
        }
        return ans;
    }
};