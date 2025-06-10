class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n-1; i++){
            int maxIndex = i;
            for(int j=i+1; j<n; j++){
                string XY = to_string(nums[maxIndex]) + to_string(nums[j]);
                string YX = to_string(nums[j]) + to_string(nums[maxIndex]);
                if(YX > XY){
                    maxIndex = j;
                }
            }
            if(maxIndex != i) swap(nums[i], nums[maxIndex]);
        }

        if(nums[0] == 0) return "0";

        string res = "";
        for(int num : nums){
            res += to_string(num);
        }

        return res;
    }
};