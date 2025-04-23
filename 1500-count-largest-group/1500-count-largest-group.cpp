class Solution {
public:
    int countLargestGroup(int n) {
        int maxSoFar = 0, res = 0;
        vector<int> mpp(37);
        for(int i=1; i<=n; i++){
            int sum = 0, num = i;
            while(num){
                sum += (num%10);
                num /= 10;
            }
            mpp[sum]++;
            if(maxSoFar < mpp[sum]){
                maxSoFar = mpp[sum];
                res = 1;
            }
            else if(maxSoFar == mpp[sum]) res++;
        }
        return res;
    }
};