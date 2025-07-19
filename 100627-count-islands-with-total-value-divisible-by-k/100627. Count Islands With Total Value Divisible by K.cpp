class Solution {
public:
    bool bfs(int i, int j, int k, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<pair<int,int>>&d){
        long long sum=0;
        queue<pair<int,int>>q; q.push({i,j}); visited[i][j] = 1;
        while (!q.empty()){
            auto [x,y] = q.front(); q.pop();
            sum+=grid[x][y];
            for (int i=0; i<4; i++){
                int nx = x+d[i].first, ny = y+d[i].second;
                if (nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && !visited[nx][ny] && grid[nx][ny]){
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return sum%k==0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m= grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m,0));
        int count=0;
        vector<pair<int,int>>d = { {-1,0},{0,1},{1,0},{0,-1} };
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (!visited[i][j] && grid[i][j]){
                    if (bfs(i,j,k, grid, visited, d)) count++;
                }
            }
        }
        return count;
    }
};