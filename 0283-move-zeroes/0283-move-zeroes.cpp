class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int currIdx = 0;

        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                nums[currIdx] = nums[i];
                currIdx++;
            }
        }

        while(currIdx < n){
            nums[currIdx] = 0;
            currIdx++;
        }
    }
};