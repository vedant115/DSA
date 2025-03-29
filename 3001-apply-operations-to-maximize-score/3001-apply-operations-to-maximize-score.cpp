class Solution {
private:
    const int MOD = 1e9 + 7;
    long long powerMOD(long long base, long long exponent){
        long long res = 1;
        while(exponent > 0){
            if(exponent % 2 == 1){
                res = (res * base) % MOD;
            }

            base = (base * base) % MOD;
            exponent /= 2;
        }
        return res;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> primeScores(n);
        for(int i=0; i<n; i++){
            int num = nums[i];
            for(int factor=2; factor<=sqrt(nums[i]); factor++){
                if(num % factor == 0){
                    primeScores[i]++;
                    while(num % factor == 0) num /= factor;
                }
            }
            if(num >= 2) primeScores[i]++;
        }

        vector<int> nextGreatorPrimeScore(n, n);
        vector<int> prevGreatorOrEqualPrimeScore(n, -1);
        stack<int> st; // Monotonic Decreasing Stack
        for(int i=0; i<n; i++){
            while(!st.empty() && primeScores[st.top()] < primeScores[i]){
                nextGreatorPrimeScore[st.top()] = i;
                st.pop();
            }
            if(!st.empty()){
                prevGreatorOrEqualPrimeScore[i] = st.top();
            }
            st.push(i);
        }
        
        priority_queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            q.push({nums[i], i});
        }

        int score = 1;
        while(k > 0){
            auto [num, index] = q.top();
            q.pop();

            long long numOfSubarr = (long long)(nextGreatorPrimeScore[index] - index) * 
                              (index - prevGreatorOrEqualPrimeScore[index]);

            long long ops = min((long long)k, numOfSubarr);

            score = (score * powerMOD(num, ops)) % MOD;
            k -= ops;
        }

        return score;
    }
};