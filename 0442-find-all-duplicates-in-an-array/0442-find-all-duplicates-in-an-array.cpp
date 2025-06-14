class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int num : nums){
            int idx = abs(num);
            if(nums[idx-1] > 0)
                nums[idx-1] *= (-1);
            else
                res.push_back(idx);
        }
        return res;
    }
};