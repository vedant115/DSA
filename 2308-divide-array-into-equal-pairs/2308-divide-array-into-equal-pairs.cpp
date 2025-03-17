class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> counter;
        for(auto num : nums){
            counter[num]++;
        }
        for(auto [num, freq] : counter){
            if(freq%2) return false;
        }
        return true;
    }
};