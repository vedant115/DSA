class Solution {
private:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> prefix(n, 0);

        for(int i=0; i<k; i++){
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            prefix[l]-=val;
            if(r+1 < n) prefix[r+1]+=val;
        }
        for(int i=1; i<n; i++){
            prefix[i] += prefix[i-1];
        }
        for(int i=0; i<n; i++){
            if(nums[i]+prefix[i] > 0) return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size();
        if(!isZeroArray(nums, queries, right)) return -1;
        while(left <= right){
            int mid = (left+right)/2;
            if(isZeroArray(nums, queries, mid)){
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};