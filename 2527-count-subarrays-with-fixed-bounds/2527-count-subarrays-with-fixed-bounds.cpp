class Solution {
public:
    long long countSubarrays(vector<int>& A, int minK, int maxK) {
        long res = 0, badI = -1, minI = -1, maxI = -1, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] < minK || A[i] > maxK) badI = i;
            if (A[i] == minK) minI = i;
            if (A[i] == maxK) maxI = i;
            res += max(0L, min(minI, maxI) - badI);
        }
        return res;
    }
};