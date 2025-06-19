class Solution {
public:
    double myPow(double base, int n) {
        double ans = 1;
        bool isNeg = false;
        long long exp = n;
        if(exp < 0){
            isNeg = true;
            exp *= -1;
        }

        // Exponentiation by squaring method
        while (exp > 0) {
            if (exp % 2 == 1) {
                exp--;
                ans *= base;
            } else {
                exp /= 2;
                base *= base;
            }
        }
        return isNeg ? 1/ans : ans;
    }
};