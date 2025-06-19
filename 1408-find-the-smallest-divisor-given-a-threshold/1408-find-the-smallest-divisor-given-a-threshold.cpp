class Solution {
private:
  int sumByD(vector<int>& nums, int d){
    int n = nums.size();
    int sum = 0;
    for(int i=0; i<n; i++){
      sum += ceil((double)(nums[i]) / (double)(d));
    }
    return sum;
  }

public:
  int smallestDivisor(vector<int> &nums, int limit) {
       int low = 1, high = *max_element(nums.begin(), nums.end());

       while(low <= high){
        int mid = (low + high) / 2;
        if(sumByD(nums, mid) <= limit){
          high = mid - 1;
        }
        else{
          low = mid + 1;
        }
       }
       return low;
    }
};