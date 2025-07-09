class Solution {
public:
    int findContentChildren(vector<int>& Student, vector<int>& Cookie) {
        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        int l = 0, r = 0;

        while(l < Student.size() && r < Cookie.size()){
            if(Student[l] <= Cookie[r]) l++;

            r++;
        }
        return l;
    }
};