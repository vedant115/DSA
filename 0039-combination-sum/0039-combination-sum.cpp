class Solution {
private:
    void func(int ind, int sum, vector<int>& list, vector<int>& nums, vector<vector<int>>& ans){
        if(sum == 0){
            ans.push_back(list);
            return;
        }
        if(sum < 0 || ind >= nums.size())
            return;
        
        list.push_back(nums[ind]);
        func(ind, sum-nums[ind], list, nums, ans);
        list.pop_back();

        func(ind+1, sum, list, nums, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        func(0, target, list, candidates, ans);
        return ans;
    }
};