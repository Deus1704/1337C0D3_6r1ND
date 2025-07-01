class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n =grid.size(), m =grid[0].size(), ans = 1e9; 
        if (n==1 && m==1 ) {
            if (!grid[0][0]) return 1;
            return -1;
        }
        if (grid[0][0] || grid[n-1][m-1]) return -1;
        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<pair<int,int>, int>>q; q.push({{0,0}, 1});
        while (!q.empty()){
            int nx = q.front().first.first;
            int ny = q.front().first.second;
            int steps = q.front().second;q.pop();
            for (int i=-1; i<2; i++){
                for (int j=-1; j<2; j++){
                    int newx = nx+i, newy=ny+j;
                    if ( (newx>=0 && newx<n)&& (newy>=0 && newy<m) && !grid[newx][newy] && !vis[newx][newy]){
                        q.push({{newx,newy},steps+1});
                        vis[newx][newy]=1;
                    }
                    if (newx == n-1 && newy == m-1){
                        ans = min(ans, steps+1);
                    }
                }
            }
        }
        if (ans != 1e9) return ans;
        return -1;
    }
};