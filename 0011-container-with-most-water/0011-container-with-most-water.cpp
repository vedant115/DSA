class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;

        int max_area = INT_MIN;
        while(l < r){
            int area = min(height[l], height[r])*(r-l);
            max_area = max(max_area, area);

            if(height[l] >= height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return max_area;
    }
};