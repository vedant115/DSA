class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int totSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(n-k == 0) return totSum;

        int start = 0;
        int sum = 0, minSum = INT_MAX;
        for(int end=0; end<n; end++){
            sum += cardPoints[end];
            while(start < n && end-start+1 >= n-k){
                if(end-start+1 == n-k)
                    minSum = min(minSum, sum);
                sum -= cardPoints[start];
                start++;
            }
        }
        return totSum - minSum;
    }
};