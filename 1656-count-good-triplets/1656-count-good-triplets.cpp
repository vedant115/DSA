class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        vector<int> prefixCnt(1001, 0);

        int res = 0;
        for(int j=0; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                if(abs(arr[j]-arr[k]) <= b){
                    int lj = arr[j] - a, lk = arr[k] - c;
                    int rj = arr[j] + a, rk = arr[k] + c;
                    int l = max(0, max(lj, lk)), r = min(1000, min(rj, rk));

                    if(l <= r){
                        if(l == 0)
                            res += prefixCnt[r];
                        else
                            res += prefixCnt[r] - prefixCnt[l-1];
                    }
                }
            }
            for(int num = arr[j]; num<1001; num++){
                prefixCnt[num]++;
            }
        }
        return res;
    }
};