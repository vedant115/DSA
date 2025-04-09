class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // It's impossible to make all elements equal to k if any element is less than k.
        if (*min_element(nums.begin(), nums.end()) < k) {
            return -1;
        }
        
        // If all elements are already k, no operations are required.
        if (*max_element(nums.begin(), nums.end()) == k) {
            return 0;
        }
        
        // Sort the array in descending order.
        sort(nums.begin(), nums.end(), greater<int>());
        
        int operations = 0;
        int current = nums.front();
        
        // Process values from highest and count distinct values > k.
        for (int num : nums) {
            if (num <= k) {
                break; // Stop once we encounter a value not greater than k.
            }
            // Only count a change when a new distinct value is encountered.
            if (num < current) {
                current = num;
                operations++;
            }
        }
        
        // If the current value (the smallest among those > k) is still not equal to k,
        // one additional operation is needed.
        if (current != k) {
            operations++;
        }
        
        return operations;
    }
};