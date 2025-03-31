class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairSum;
        for(int i=0; i<n-1; i++){
            pairSum.push_back(weights[i]+weights[i+1]);
        }
        sort(pairSum.begin(), pairSum.end());
        long long minScore = 0, maxScore = 0;
        for(int i=0; i<k-1; i++){
            minScore += pairSum[i];
            maxScore += pairSum[n-2-i];
        }
        return maxScore - minScore;
    }
};