class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int rem = grid[0][0]%x;
        
        for(auto& row : grid){
            for(auto& num : row){
                if (num % x != rem) {
                    return -1;
                }
                nums.push_back(num);
            }
        }

        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        int res = 0;
        for(auto& row : grid){
            for(auto& num : row){
                res+=(abs(median-num)/x);
            }
        }

        return res;
    }
};