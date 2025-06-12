class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res(n);

        int startPtr = 0, endPtr = n-1;
        if(n%2) startPtr = (n/2);
        else startPtr = (n/2)-1;
        
        for(int i=0; i<n; i++){
            if(i % 2 == 0){
                res[i] = nums[startPtr];
                startPtr--;
            }
            else{
                res[i] = nums[endPtr];
                endPtr--;
            }
        }
        nums = res;
    }
};