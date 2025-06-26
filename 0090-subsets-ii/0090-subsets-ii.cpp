class Solution {
public:
    void func(int ind, vector<int>& list, vector<int>& nums, vector<vector<int>>& ans){
        if(ind > nums.size()-1){
            ans.push_back(list);
            return;
        }
        list.push_back(nums[ind]);
        func(ind+1, list, nums, ans);
        list.pop_back();

        int nextInd = ind+1;
        while(nextInd < nums.size() && nums[nextInd] == nums[ind])
            nextInd++;
        func(nextInd, list, nums, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> list;
        sort(nums.begin(), nums.end());
        func(0, list, nums, ans);

        return ans;
    }
};