class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        // Build prefix sum
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];

        int minLen = n + 1;

        for (int i = 0; i < n; ++i) {
            // Find the smallest j such that prefix[j] - prefix[i] >= target
            int toFind = prefix[i] + target;
            auto bound = lower_bound(prefix.begin(), prefix.end(), toFind);

            if (bound != prefix.end()) {
                int j = bound - prefix.begin();
                minLen = min(minLen, j - i);
            }
        }

        return minLen == n + 1 ? 0 : minLen;
    }
};