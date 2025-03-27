class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dominant = nums[0];
        int count = 0;
        for(int num : nums){
            if(num == dominant){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                dominant = num;
                count = 1;
            }
        }
        int dominantCount = 0;
        for(int num : nums){
            if(num == dominant) dominantCount++;
        }
        
        count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == dominant){
                count++;
            }
            if(count*2 > i+1 && (dominantCount-count)*2 > n-i-1){
                return i;
            }
        }
        return -1;
    }
};