class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int last = INT_MIN, cnt = 0, res = 0;
        for(int i=0; i<n; i++){
            if(nums[i] - 1 == last){
                cnt++;
                last = nums[i];
            }
            else if(nums[i] == last){
                continue;
            }
            else{
                cnt = 1;
                last = nums[i];
            }
            res = max(res, cnt);
        }
        return res;
    }
};