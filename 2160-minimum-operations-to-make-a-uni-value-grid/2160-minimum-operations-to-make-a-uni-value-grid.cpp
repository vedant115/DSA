class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int rem = grid[0][0] % x;

        for(auto& row : grid){
            for(int num : row){
                if (num % x != rem) return -1;
                nums.push_back(num);
            }
        }

        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        int ops = 0;
        for(int num : nums){
            ops += (abs(median-num) / x);
        }

        return ops;
    }
};