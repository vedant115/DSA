class Solution {
public:
    void merge(vector<long long>& prefix, int low, int mid, int high, int lower, int upper, int& res){
        int j = mid, k = mid;
        for (int i = low; i < mid; ++i) {
            while (k < high && prefix[k] - prefix[i] < lower) ++k;
            while (j < high && prefix[j] - prefix[i] <= upper) ++j;
            res += j - k;
        }

        // Merge step
        vector<long long> sorted;
        int left = low, right = mid;
        while (left < mid && right < high) {
            if (prefix[left] <= prefix[right]) {
                sorted.push_back(prefix[left++]);
            } else {
                sorted.push_back(prefix[right++]);
            }
        }
        while (left < mid) sorted.push_back(prefix[left++]);
        while (right < high) sorted.push_back(prefix[right++]);

        for (int i = 0; i < sorted.size(); ++i) {
            prefix[low + i] = sorted[i];
        }
    }
    void mergeSort(vector<long long>& prefix, int low, int high, int lower, int upper, int& res) {
        if (high - low <= 1) return;

        int mid = (low + high) / 2;
        mergeSort(prefix, low, mid, lower, upper, res);
        mergeSort(prefix, mid, high, lower, upper, res);
        merge(prefix, low, mid, high, lower, upper, res);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];

        int res = 0;
        mergeSort(prefix, 0, n + 1, lower, upper, res);
        return res;
    }
};