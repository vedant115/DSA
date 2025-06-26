class Solution {
public:
    void func(int ind, int sum, vector<int>& list, vector<int>& nums, vector<vector<int>>& ans){
        if(sum == 0){
            ans.push_back(list);
            return;
        }
        if(sum < 0 || ind > nums.size()-1)
            return;

        list.push_back(nums[ind]);
        func(ind+1, sum-nums[ind], list, nums, ans);
        list.pop_back();

        int ele = nums[ind];
        while(ind < nums.size() && nums[ind] == ele)
            ind++;
        func(ind, sum, list, nums, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> list; 

        sort(candidates.begin(), candidates.end()); 

        func(0, target, list, candidates, ans);

        return ans; 
    }
};