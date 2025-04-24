class Solution {
private:
    int countAtMostK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        unordered_map<int, int> freq;
        int left = 0, right = 0, res = 0;
        
        while (right < nums.size()) {
            freq[nums[right]]++;
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
            res += (right - left + 1);
            right++;
        }
        return res;
    }
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> totalSet(nums.begin(), nums.end());
        int totalDistinct = totalSet.size();

        return countAtMostK(nums, totalDistinct) - countAtMostK(nums, totalDistinct - 1);
    }
};