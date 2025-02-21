class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int maxSoFar = -1;  // Track max value encountered before i-1
        
        for (int i = 0; i < n - 2; i++) {
            maxSoFar = max(maxSoFar, nums[i]);  // Track max up to index i
            if (maxSoFar > nums[i + 2]) return false;  // Found a non-local global inversion
        }
        
        return true;  // If no such case found, local == global
    }
};