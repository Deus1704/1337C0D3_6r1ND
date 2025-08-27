// This BFS Solution passess 554/561 Test Cases. TLE for the rest 
// Completely Implemented by me.
// class Solution {
// public:
//     bool isvalid(int i, int j, int n, int m){
//         if (i>=0 && i<n && j>=0 && j<m) return true;
//         return false;
//     }
//     int lenOfVDiagonal(vector<vector<int>>& grid) {
//         int n=grid.size(), m=grid[0].size();
//         int max_steps = 0;
//         vector<pair<int,int>>d = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
//         // The ds of the queue is;
//         //  0  1   2       3        4
//         // {i, j, can, direction, steps};
//         queue<vector<int>>q; bool atleast_one_traversal = 0;
//         for (int i=0; i<n; i++){
//             for (int j=0; j<m; j++){
//                 if (grid[i][j] == 1){
//                     atleast_one_traversal = 1;
//                     // Try starting to move in all the 4 directions;
//                     for (int k=0; k<4; k++){
//                         int newx = i+d[k].first, newy = j+d[k].second;
//                         if ( isvalid(newx, newy, n ,m) && grid[newx][newy] == 2){
//                             q.push({newx, newy, 1, k, 1}); 
//                         }
//                     }
//                 }
//             }
//         }
//         while (!q.empty()){
//             vector<int> top = q.front(); q.pop(); 
//             int i = top[0], j= top[1], can=top[2], direction = top[3], steps=top[4];
//             max_steps = max(max_steps, steps);
//             // try moving in the direction diagonal
//             int newx = i+d[direction].first, newy = j+d[direction].second;
//             if ( isvalid(newx, newy, n, m) && ((grid[i][j]==2 && grid[newx][newy]==0) || (grid[i][j]==0 && grid[newx][newy]==2)) ){
//                 // then its possible to keep going;
//                 q.push({newx, newy, can, direction, steps+1});
//             }
//             // Try moving in the clockwise 90 degree turn if possible
//             int newx_clock = i+d[ (direction+1)%4 ].first, newy_clock = j+d[ (direction+1)%4 ].second;
//             if ( isvalid(newx_clock, newy_clock, n, m) && can && ((grid[i][j]==2 && grid[newx_clock][newy_clock]==0) || (grid[i][j]==0 && grid[newx_clock][newy_clock]==2))){
//                 q.push({newx_clock, newy_clock, can^1, (direction+1)%4, steps+1});
//             }
//         }
//         // cout<<max_steps<<endl;
//         return max_steps+atleast_one_traversal;
//     }
// };
constexpr int d[5] = {1, 1, -1, -1, 1};
int dp[500][500][4][2];
class Solution {
public:
    int n, m;
    bool isOutSide(int i, int j) { 
        return i<0 || i>=n || j<0 || j>=m; 
    }
    int dfs(int i, int j, int dir, bool turn, int nxt, vector<vector<int>>& grid) {
        if (dp[i][j][dir][turn]!=-1) return dp[i][j][dir][turn];
        
        int ans=1, x=grid[i][j];

        // Move in the current direction
        int s=i+d[dir], t=j+d[dir+1];
        if (!isOutSide(s, t)) { 
            int y=grid[s][t];
            if (nxt==y)  // continue moving in the same diagonal
                ans=max(ans, 1+dfs(s, t, dir, turn, nxt^2, grid));
        }

        // Try turning to the next diagonal direction
        if (!turn) { 
            const int newDir=(dir+1)&3;// same %4
            int u=i+d[newDir], v=j+d[newDir+1];
            if (!isOutSide(u, v)) {
                const int z=grid[u][v];
                if (nxt==z)  // to turn to the next diagonal
                    ans=max(ans, 1+dfs(u, v, newDir, 1, nxt^2, grid));
            }
        }

        return dp[i][j][dir][turn]=ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        
        for (int i=0; i<n; i++)// fill dp 
            for(int j=0; j<m; j++)
                memset(dp[i][j], -1, sizeof(dp[i][j]));

        int ans=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==1) { // Start from cells that are part of the path
                    for (int d=0; d<4; d++) 
                        ans=max(ans, dfs(i, j, d, 0, 2,  grid));
                }
            }
        }
        return ans;
    }
};