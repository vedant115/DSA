class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;

        for(int i=0; i<n; i++){
            hash[nums[i]]++;
            if(hash[nums[i]] > n/2) return nums[i];
        }
        return nums[n/2];
    }
};