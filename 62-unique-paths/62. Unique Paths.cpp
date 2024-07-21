class Solution {
    private:
    long long f(int m, int n, vector<vector<int>>& dp){
        if (m<0 || n<0) return 0;
        if (m==0 && n==0) return 1;
        if (dp[m][n]!=-1) return dp[m][n];
        int left = f(m,n-1,dp), up = f(m-1,n,dp);
        return dp[m][n] = left+up; 
    }
public:
    long long uniquePaths(int m, int n) {
        vector<vector<int>> dp(101, vector<int>(101,-1));
        return f(m-1,n-1,dp);
    }
};