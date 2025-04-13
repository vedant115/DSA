class Solution {
public:
    int M = 1e9+7;
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % M;
            }
            base = (base * base) % M;
            exp /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long temp = power(20, n/2);
        return (n & 1) ? temp * 5 % M : temp % M;
    }
};