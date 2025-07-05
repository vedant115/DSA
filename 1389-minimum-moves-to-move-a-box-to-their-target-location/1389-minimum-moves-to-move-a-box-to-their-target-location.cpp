class Solution {
public:
    bool valid(int x, int y, int m, int n, vector<vector<char>>& grid){
        return x>=0 && x<m && y>=0 && y<n && grid[x][y]!='#';
    };
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int bx, by, px, py, tx, ty;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='B') bx=i, by=j;
                if(grid[i][j]=='S') px=i, py=j;
                if(grid[i][j]=='T') tx=i, ty=j;
            }
        }
        
        vector<vector<vector<vector<bool>>>> vis(m,vector<vector<vector<bool>>>(n,vector<vector<bool>>(m,vector<bool>(n,false))));
        queue<tuple<int,int,int,int,int>> q;
        q.push({bx,by,px,py,0});
        vis[bx][by][px][py]=true;
        int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            auto [bx,by,px,py,push]=q.front();q.pop();
            if(bx==tx && by==ty) return push;
            for(int d=0;d<4;d++){
                int nbx=bx+dirs[d][0], nby=by+dirs[d][1];
                int opx=bx-dirs[d][0], opy=by-dirs[d][1];
                if(!valid(nbx,nby, m, n, grid) || !valid(opx,opy, m, n, grid)) continue;
                // Inner BFS: can player reach opx, opy without crossing box?
                queue<pair<int,int>> pq;
                vector<vector<bool>> pvis(m,vector<bool>(n,false));
                pq.push({px,py});
                pvis[px][py]=true;
                while(!pq.empty()){
                    auto [cx,cy]=pq.front();pq.pop();
                    if(cx==opx && cy==opy) break;
                    for(int k=0;k<4;k++){
                        int nx=cx+dirs[k][0], ny=cy+dirs[k][1];
                        if(valid(nx,ny, m, n, grid) && !pvis[nx][ny] && !(nx==bx && ny==by)){
                            pvis[nx][ny]=true;
                            pq.push({nx,ny});
                        }
                    }
                }
                if(!pvis[opx][opy]) continue;
                if(!vis[nbx][nby][bx][by]){
                    vis[nbx][nby][bx][by]=true;
                    q.push({nbx,nby,bx,by,push+1});
                }
            }
        }
        return -1;
    }
};