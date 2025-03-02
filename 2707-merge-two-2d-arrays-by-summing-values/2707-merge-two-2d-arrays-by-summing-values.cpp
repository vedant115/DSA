class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        int ptr1 = 0, ptr2 = 0;
        int m = nums1.size(), n = nums2.size();

        while(ptr1 < m && ptr2 < n){
            vector<int> temp(2, 0);
            if(nums1[ptr1][0] == nums2[ptr2][0]){
                temp[0] = nums1[ptr1][0];
                temp[1] = nums1[ptr1][1] + nums2[ptr2][1];
                ptr1++, ptr2++;
            }
            else if(nums1[ptr1][0] < nums2[ptr2][0]){
                temp[0] = nums1[ptr1][0];
                temp[1] = nums1[ptr1][1];
                ptr1++;
            }
            else{
                temp[0] = nums2[ptr2][0];
                temp[1] = nums2[ptr2][1];
                ptr2++;
            }
            res.push_back(temp);
        }

        while(ptr1 < m){
            res.push_back(nums1[ptr1]);
            ptr1++;
        }

        while(ptr2 < n){
            res.push_back(nums2[ptr2]);
            ptr2++;
        }

        return res;
    }
};