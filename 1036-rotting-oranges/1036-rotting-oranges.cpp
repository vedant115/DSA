class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int total = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i, j});
    
                if(grid[i][j] != 0) total++;
            }
        }

        int count = 0, time = 0;
        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!q.empty()){
            int rottenCnt = q.size();
            count += rottenCnt;
            
            while(rottenCnt--){
                auto cell = q.front();
                q.pop();
                int row = cell.first, col = cell.second;
                for(auto d : dir){
                    int nRow = row + d[0], nCol = col + d[1];
                    if((nRow >= 0 && nRow < m) && (nCol >= 0 && nCol < n) && grid[nRow][nCol] == 1){
                        q.push({nRow, nCol});
                        grid[nRow][nCol] = 2;
                    }
                }
            }
            if(q.size() > 0) time++;
        }

        if(count == total) return time;
        return -1;
    }
};