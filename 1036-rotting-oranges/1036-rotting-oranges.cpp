class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;

        // Initialize the queue with rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        // If there are no fresh oranges, return 0
        if (freshCount == 0) return 0;

        int result = -1;
        int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // BFS to spread the rot
        while (!q.empty()) {
            int size = q.size();
            result++;  // Increment time at each level

            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nrow = row + directions[d][0];
                    int ncol = col + directions[d][1];

                    // If it's a fresh orange, rot it and add it to the queue
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        freshCount--;
                    }
                }
            }
        }

        // If there are still fresh oranges left, return -1
        return freshCount == 0 ? result : -1;
    }
};