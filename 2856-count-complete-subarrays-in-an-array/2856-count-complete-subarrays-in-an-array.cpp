class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> totalSet(nums.begin(), nums.end());
        int totalDistinct = totalSet.size();
        int res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            unordered_set<int> currSet;
            for (int j = i; j < nums.size(); ++j) {
                currSet.insert(nums[j]);
                if (currSet.size() == totalDistinct) {
                    res++;
                }
            }
        }
        return res;
    }
};
