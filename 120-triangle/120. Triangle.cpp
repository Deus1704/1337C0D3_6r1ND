class Solution {
public:
    int rec(int i, int j, const vector<vector<int>>&triangle, vector<vector<int>>&dp){
        // base cases
        if (i<0 || j<0 || j>i) return 1e9;
        if (i==0 && j==0) return triangle[0][0];
        // cache check
        if (dp[i][j]!=-1) return dp[i][j]; 
        // trying up
        int up = 0;if (j<=i+1) up=triangle[i][j]+rec(i-1,j,triangle,dp);
        // trying left
        int left = triangle[i][j]+rec(i-1,j-1,triangle,dp);
        // return min
        return dp[i][j]=min(up,left);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(), m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=1e9;
        for (int i=0; i<m; i++){
            ans = min(ans, rec(n-1,i, triangle, dp));
        }
        return ans;
    }
};