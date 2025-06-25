class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0, up = 0, down = 0;
        for (int i = 1; i < A.size(); ++i) {
            // If we are going down and current element is greater than prev
            // MEANS last mountain ended And the current mountain began (Up will
            // be updated below)
            if (down > 0 && A[i - 1] < A[i] || A[i - 1] == A[i])
                up = down = 0;

            // If current element is greater then previous then we are going up
            // Else we are going down the mountain
            A[i] > A[i - 1] ? up++ : down++;

            if (up > 0 && down > 0)
                res = max(res, up + down + 1);
        }
        return res;
    }
};