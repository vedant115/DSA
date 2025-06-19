class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int c = 1, prev = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - nums[prev] <= k) continue;
            c++; prev = i;
        }
        return c;   
    }
};