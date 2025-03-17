class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> needsPair(501, false);

        for(auto num : nums){
            needsPair[num] = !needsPair[num];
        }

        for(auto num : nums){
            if(needsPair[num]) return false;
        }
        return true;
    }
};