class Solution {
private:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> st;
        int largestArea = 0, n = heights.size();

        for (int i = 0; i < n; i++) {
            int h = heights[i];
            while (!st.empty() && heights[st.top()] >= h) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                largestArea = max(largestArea, height * width);
            }
            st.push(i);
        }
        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            largestArea = max(largestArea, height * width);
        }
        return largestArea;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = (matrix[i][j] == '0') ? 0 : heights[j] + 1;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};
