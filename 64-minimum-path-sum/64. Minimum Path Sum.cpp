class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
        // base cases;
        if (i<0 || j<0) return 1e8;
        if (i==0 && j==0) return grid[0][0];
        // cache check
        if (dp[i][j]!=-1) return dp[i][j]; 
        // try left
        int left = grid[i][j]+rec(i,j-1, grid, dp);
        // try up
        int up = grid[i][j]+rec(i-1,j, grid, dp);

        return dp[i][j]=min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return rec(n-1,m-1, grid, dp);   
    }
};