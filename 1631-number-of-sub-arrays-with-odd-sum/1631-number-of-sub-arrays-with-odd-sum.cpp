class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), res = 0, mod = 1e9 + 7;
        int oddCnt = 0, evenCnt = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum%2 == 0){ 
                res += oddCnt;
                evenCnt++;
            }
            else{
                res++;
                res += evenCnt;
                oddCnt++;
            }
            res = res%mod;
        }
        return res;
    }
};