class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long low = 0, high = 0;
        long long curr = 0;
        for(int& diff : differences){
            curr += diff;
            low = min(low, curr);
            high = max(high, curr);
        }
        int count = (upper-lower) - (high-low) + 1;
        return count > 0 ? count : 0;
    }
};