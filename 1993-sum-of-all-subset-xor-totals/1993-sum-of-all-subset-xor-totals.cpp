class Solution {
private:
    int solve(int i, vector<int>& nums, int currXOR){
        if(i == nums.size()) return currXOR;

        int include = solve(i+1, nums, nums[i]^currXOR);
        int exclude = solve(i+1, nums, currXOR);

        return include + exclude;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return solve(0, nums, 0);
    }
};