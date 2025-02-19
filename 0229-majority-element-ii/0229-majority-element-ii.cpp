class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;

        for(int i=0; i<n; i++){
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != ele1){
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for(int num : nums){
            if(num == ele1) cnt1++;
            if(num == ele2) cnt2++;
        }
        
        vector<int> res;
        int th = n/3;
        if(cnt1 > th) res.push_back(ele1);
        if(cnt2 > th) res.push_back(ele2);

        return res;
    }
};