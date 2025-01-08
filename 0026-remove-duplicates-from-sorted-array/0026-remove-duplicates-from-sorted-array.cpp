class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;

        for(int num : nums){
            s.insert(num);
        }

        int n = s.size();
        int j =0;

        for(int num : s){
            nums[j++] = num;
        }

        return n;
    }
};