class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> tripletSet;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                set<long long> hashSet;
                for(int k=j+1; k<n; k++){
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long cmpt = (long long)target - sum;
                    if(hashSet.count(cmpt)){
                        vector<int> triplet = {nums[i], nums[j], nums[k], (int)cmpt};
                        sort(triplet.begin(), triplet.end());
                        tripletSet.insert(triplet);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(tripletSet.begin(), tripletSet.end());
    }
};