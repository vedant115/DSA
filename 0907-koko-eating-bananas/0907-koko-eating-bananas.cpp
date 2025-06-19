class Solution {
private:
    long calcTime(vector<int> nums, int k){
        int n = nums.size();
        long ans = 0;
        for(int i=0; i<n; i++){
            ans += ceil((double)(nums[i])/ (double)(k));
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int> nums, int h) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            
            if(calcTime(nums, mid) <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};