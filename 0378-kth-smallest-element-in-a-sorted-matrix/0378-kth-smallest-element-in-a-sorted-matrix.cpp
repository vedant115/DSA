class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1], ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            int countLessOrEqual = 0;
            for (int i = 0; i < n; i++){
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				countLessOrEqual += pos;
			}
            if (countLessOrEqual >= k) {
                ans = mid;
                right = mid - 1; // try to looking for a smaller value in the left side
            } else left = mid + 1; // try to looking for a bigger value in the right side
        }
        return ans;
    }
};