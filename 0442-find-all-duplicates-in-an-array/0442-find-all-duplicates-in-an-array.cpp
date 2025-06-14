class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        vector<int> res;
        for(auto& [num, cnt] : mp){
            if(cnt > 1) res.push_back(num);
        }
        return res;
    }
};