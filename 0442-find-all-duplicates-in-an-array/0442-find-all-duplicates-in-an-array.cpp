class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n, 0);
        vector<int> res;
        for(int num : nums){
            if(!visited[num-1])
                visited[num-1] = 1;
            else
                res.push_back(num);
        }
        return res;
    }
};