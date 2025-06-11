class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> numIdx(n, vector<int>(2, -1));
        for (int i = 0; i < n; i++) {
            numIdx[i][0] = nums[i];
            numIdx[i][1] = i;
        }

        sort(numIdx.begin(), numIdx.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numIdx[left][0] + numIdx[right][0];
            if (sum == target) {
                return {numIdx[left][1], numIdx[right][1]};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {-1, -1};
    }
};