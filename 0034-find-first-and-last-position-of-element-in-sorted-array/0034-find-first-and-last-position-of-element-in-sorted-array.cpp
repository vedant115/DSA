class Solution {
private:
    int lowerBound(vector<int>& nums, int x) {
        int n = nums.size();
        int res = -1;
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == x){
                res = mid;
                high = mid-1;
            }
            else if(nums[mid] >= x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
    int upperBound(vector<int>& nums, int x) {
        int n = nums.size();
        int res = -1;
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == x){
                res = mid;
                low = mid+1;
            }
            else if(nums[mid] > x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);
        return {lb, ub};
    }
};