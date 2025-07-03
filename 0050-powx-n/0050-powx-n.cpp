class Solution {
private:
    double fastPow(double x, long long n) {
        if (n == 0) return 1;
        if (n % 2 == 0)
            return fastPow(x * x, n / 2);
        else
            return x * fastPow(x, n - 1);
    }
public:
    double myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        return fastPow(x, exp);
    }
};
