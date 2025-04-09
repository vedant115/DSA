class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] < k) return -1;
            else if(nums[0] == k) return 0;
            else return 1;
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int prev = nums[0], res = 0, i = 0;
        for(i=1; i<n; i++){
            if(nums[i] != prev){
                res++;
            }
            if(nums[i] < k) break;
            prev = nums[i];
        }
        if(nums[n-1] > k) res++;
        return i < n ? -1 : res;
    }
};