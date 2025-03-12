class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pos = -1, neg = -1;

        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] < 0){
                left = mid + 1;
                neg = mid;
            }
            else{
                right = mid - 1;
            }
        }

        left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] > 0){
                right = mid - 1;
                pos = mid;
            }
            else{
                left = mid + 1;
            }
        }
        cout << neg << " " << pos;
        return (pos == -1) ? neg+1 : max(neg+1, n-pos);
    }
};