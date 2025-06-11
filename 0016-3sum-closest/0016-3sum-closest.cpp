class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closest_sum = INT_MAX / 2;
        for(int i=0; i<n; i++){
            int l = i+1, r = n-1;
            while(l < r){
                int curr_sum = nums[i] + nums[l] + nums[r];

                if(abs(curr_sum - target) < abs(closest_sum - target)){
                    closest_sum = curr_sum;
                }

                if(curr_sum > target){
                    r--;
                }
                else if(curr_sum < target){
                    l++;
                }
                else{
                    return target;
                }
            }
        }
        return closest_sum;
    }
};