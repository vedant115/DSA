class Solution {
private:
    // 0 : top-left, 1 : top-right, 2 : bottom-right, 3 : bottom-left
    vector<vector<int>> dir = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

    int func(int row, int col, int numReq, int d, int turn, vector<vector<int>>& grid){
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size()) return 0;
        if(grid[row][col] != numReq) return 0;

        int newNumReq = (numReq == 2) ? 0 : 2;
        
        int alongDiag = 1 + func(row+dir[d][0], col+dir[d][1], newNumReq, d, turn, grid);
        int rotateNinety = 0;
        if(!turn) rotateNinety = 1 + func(row+dir[(d+1)%4][0], col+dir[(d+1)%4][1], newNumReq, (d+1)%4, 1, grid);

        return max(alongDiag, rotateNinety);
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        int maxSeg = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    maxSeg = 0;
                    for(int d=0; d<4; d++){
                        maxSeg = max(maxSeg, 1+func(i+dir[d][0], j+dir[d][1], 2, d, 0, grid));
                    }
                }
                res = max(res, maxSeg);
            }
        }

        return res;
    }
};