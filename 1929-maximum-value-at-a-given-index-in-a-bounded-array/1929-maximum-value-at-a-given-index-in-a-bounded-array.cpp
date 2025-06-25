class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int low = 1, high = maxSum;
        int emptyR = n - index - 1, emptyL = index;
        int res = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long el = mid - 1;
            long long rightSum = 0, leftSum = 0;
            if (emptyR <= el) {
                rightSum += (el * (el + 1) / 2) - ((el - emptyR + 1) * (el - emptyR) / 2);
            } else {
                rightSum += (el * (el + 1) / 2) + (emptyR - el);
            }

            if (emptyL <= el) {
                leftSum += (el * (el + 1) / 2) - ((el - emptyL + 1) * (el - emptyL) / 2);
            } else {
                leftSum += (el * (el + 1) / 2) + (emptyL - el);
            }

            if (leftSum + mid + rightSum <= maxSum) {
                low = mid + 1;
                res = mid;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};