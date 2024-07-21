class Solution {
    private:
    int minSum(int m, int n,vector<vector<int>>& grid, vector<vector<int>>& dp){
        if (m<0 || n<0) return INT_MAX;
        if (m==0 && n==0) return grid[0][0];
        if (dp[m][n]) return dp[m][n];
        int ans = 0;
        int leftSum = minSum(m,n-1,grid, dp), upSum = minSum(m-1,n,grid, dp);
        ans = grid[m][n]+ min(leftSum, upSum);
        return dp[m][n]= ans;
    }
    public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp (201, vector<int>(201,0));
        return minSum(grid.size()-1,grid[0].size()-1, grid, dp);
    }
};