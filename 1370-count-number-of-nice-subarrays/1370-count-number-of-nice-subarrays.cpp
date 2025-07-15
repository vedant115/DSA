class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> oddFreq;
        int currOdds = 0, res = 0;
        oddFreq[0] = 1;
        for(int num : nums){
            if(num%2) currOdds++;
            if(oddFreq.find(currOdds - k) != oddFreq.end()){
                res += oddFreq[currOdds - k];
            }
            oddFreq[currOdds]++;
        }
        return res;
    }
};