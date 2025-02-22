class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(int num : nums){
            st.insert(num);
        }

        int res = 0;
        for(int num : st){
            if(st.find(num-1) == st.end()){
                int x = num;
                int cnt = 1;
                while(st.find(x+1) != st.end()){
                    x++;
                    cnt++;
                }
                res = max(res, cnt);
            }
        }

        return res;
    }
};