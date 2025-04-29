class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        long long maxEleCnt = 0, left = 0, res = 0;
        for(int right=0; right<n; right++){
            if(nums[right] == maxEle) maxEleCnt++;
            while(maxEleCnt > k || (left <= right && maxEleCnt == k && nums[left] != maxEle)){
                if(nums[left] == maxEle) maxEleCnt--;
                left++;
            }
            if(maxEleCnt == k) res += (left+1);
        }
        return res;
    }
};