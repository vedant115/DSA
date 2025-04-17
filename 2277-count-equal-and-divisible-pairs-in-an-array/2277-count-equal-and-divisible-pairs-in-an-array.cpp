class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> map;
        int res = 0, n = nums.size();
        for(int i=0; i<n; i++){
            if(map.find(nums[i]) != map.end()){
                for(int ind : map[nums[i]]){
                    if((i*ind) % k == 0) res++;
                }
            }
            map[nums[i]].push_back(i);
        }
        return res;
    }
};