class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Count the distinct numbers that are strictly greater than k.
        unordered_set<int> distinctAboveK;
        for (int num : nums) {
            // Check feasibility: if any element is less than k, return -1.
            if(num == k){
                continue;
            }
            else if (num < k) {
                return -1;
            }
            else {
                distinctAboveK.insert(num);
            }
        }
        
        // The number of operations required is exactly the number of distinct numbers above k.
        return distinctAboveK.size();
    }
};