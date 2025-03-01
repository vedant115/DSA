class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size(), idx = 0;
        int i;
        for(i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }

            if(nums[i] != 0) swap(nums[i], nums[idx]);
            if(nums[idx] != 0) idx++;
        }
        swap(nums[i], nums[idx]);
        return nums;
    }
};