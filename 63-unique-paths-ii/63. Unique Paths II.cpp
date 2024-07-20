class Solution {
    private:
    int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if (i==0 && j==0) return obstacleGrid[i][j] ? 0:1;
        if (i<0 || j<0 || obstacleGrid[i][j]) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int left = f(i,j-1, obstacleGrid, dp);
        int up = f(i-1,j, obstacleGrid, dp);
        return dp[i][j] = left+up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp (101, vector<int>(101,-1));
        return f(obstacleGrid.size()-1,obstacleGrid[0].size()-1, obstacleGrid, dp);
    }
};