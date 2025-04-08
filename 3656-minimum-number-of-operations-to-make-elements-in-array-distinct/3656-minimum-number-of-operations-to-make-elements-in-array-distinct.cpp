class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        vector<int> unqIdx(n, 0);
        
        int cnt = 0;
        for(int i=n-1; i>=0; i--){
            if(seen.find(nums[i]) == seen.end()){
                seen.insert(nums[i]);
                cnt++;
            }
            unqIdx[i] = cnt;
        }
        if(unqIdx[0] == n) return 0;

        cnt = 0;
        for(int i=0; i<n; i+=3){
            if(unqIdx[i] != n-i) cnt++;
            else break;
        }
        return cnt;
    }
};