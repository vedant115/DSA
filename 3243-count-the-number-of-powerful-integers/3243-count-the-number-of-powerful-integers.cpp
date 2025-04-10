class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string lower = to_string(start-1), upper = to_string(finish);
        long long x = calculate(upper, s, limit), y = calculate(lower, s, limit);
        cout << x << " " << y;
        return x - y;
    }

    long long calculate(string bound, string suffix, int limit){
        long long ans = 0;
        if(bound.size() < suffix.size()) return 0;
        if(bound.size() == suffix.size()){
            if(bound >= suffix) return 1;
            else return 0;
        }

        int n = bound.size() - suffix.size();
        for(int i=0; i<n; i++){
            if((bound[i]-'0') > limit){
                ans += pow(limit+1, n-i);
                return ans;
            }
            else{
                ans += (bound[i]-'0') * pow(limit+1, n-i-1);
            }
        }

        if(bound.substr(n, suffix.size()) >= suffix) ans++;
        return ans;
    }
};