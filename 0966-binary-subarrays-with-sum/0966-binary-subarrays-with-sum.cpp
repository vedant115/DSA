class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> sumFreq;
        int currSum = 0, res = 0;
        sumFreq[0] = 1;
        for(int i=0; i<nums.size(); i++){
            currSum += nums[i];
            if(sumFreq.find(currSum - goal) != sumFreq.end()){
                res += sumFreq[currSum - goal];
            }
            sumFreq[currSum]++;
        }
        return res;
    }
};