class Solution {
public:
    int func(vector<int>& nums, int k){
        int r = 0, l = 0, noOdd = 0, cnt = 0;
        while(r < nums.size()){
            if(nums[r]%2) noOdd++;
            while(noOdd > k){
                if(nums[l]%2) noOdd--;
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);
    }
};