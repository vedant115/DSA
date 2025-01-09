class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
    int sum_expected = n * (n + 1) / 2; // Sum of numbers from 0 to n
    int sum_actual = 0;
    for (int num : nums) {
        sum_actual += num; // Sum of array elements
    }
    return sum_expected - sum_actual; // The missing number
    }
};