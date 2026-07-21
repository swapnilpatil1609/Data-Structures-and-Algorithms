class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        q.push({{0,0},1});
        vis[0][0]=1;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            if(row==n-1 && col==m-1) return dist;
            for(int delRow=-1;delRow<=1;delRow++){
                for(int delCol=-1;delCol<=1;delCol++){
                    int nrow = row + delRow;
                    int ncol = col + delCol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && vis[nrow][ncol]==0){
                        q.push({{nrow,ncol},dist+1});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
        return -1;
    }
};