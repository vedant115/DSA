class Solution{
public:
    int trap(vector<int> &height) {
        int n = height.size(), left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0, total = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] < leftMax) total += leftMax - height[left];
                else leftMax = height[left];
                left++;
            } else {
                if (height[right] < rightMax) total += rightMax - height[right];
                else rightMax = height[right];
                right--;
            }
        }
        return total;
    }
};