class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int num=low; num<=high; num++){
            string s = to_string(num);
            int n = s.size();
            if(n % 2) continue;
            int i = 0, sum = 0;
            for(i=0; i<n/2; i++){
                sum += s[i]-'0';
            }
            for(; i<n; i++){
                sum -= s[i]-'0';
            }
            if(sum == 0) cnt++;
        }
        return cnt;
    }
};