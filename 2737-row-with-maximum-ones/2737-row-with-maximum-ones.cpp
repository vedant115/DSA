class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
        int n = arr.size();
        int maxCnt = -1;
        int maxInd = -1;

        for(int i = 0; i < n; i++) {
            int count = count_if(arr[i].begin(), arr[i].end(), [](int x){ return x == 1; });
            if(count > maxCnt) {
                maxCnt = count;
                maxInd = i;
            }
        }
        return {maxInd, maxCnt};
    }
};