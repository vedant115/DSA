class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        int dominant = -1;
        for(auto& f : freq){
            if(f.second * 2 > n){
                dominant = f.first;
                break;
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == dominant){
                count++;
            }
            if(count*2 > i+1 && (freq[dominant]-count)*2 > n-i-1){
                return i;
            }
        }
        return -1;
    }
};