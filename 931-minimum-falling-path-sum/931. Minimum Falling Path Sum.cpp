// Working Recursion+Memoised code still TLE for larger cases. TC-> O(N^2)+Time due to recursion calls.
// class Solution {
// public:
//     int rec(int i, int j, const vector<vector<int>>& matrix, vector<vector<int>>& dp, int n){
//         // base cases;
//         if (i<0 || j<0 || j>=n) return 1e9; // keep this nigga above since there might be a case where rec(0,-1) be called.
//         if (i==0 && j>=0) return matrix[0][j];
//         // cache check
//         if (dp[i][j]!=-1) return dp[i][j];
//         // Straight up
//         int sup = matrix[i][j]+rec(i-1,j,matrix, dp,n);
//         // left up
//         int lup = matrix[i][j]+rec(i-1,j-1,matrix, dp,n);
//         // Right up
//         int rup = matrix[i][j]+rec(i-1,j+1,matrix, dp,n);

//         return dp[i][j]=min({sup,lup,rup});
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         vector<vector<int>>dp(n, vector<int>(n,-1));
//         int ans=1e9;
//         for (int i=0; i<n; i++){
//             ans=min(ans, rec(n-1,i,matrix, dp,n));
//         }
//         return ans;
//     }
// };
// Tabulation approach, still TC->O(N^2) but no overhead of recursion calls hence no TLE.
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for (int i=0; i<n; i++) dp[0][i]=matrix[0][i];
        for (int i=1; i<n; i++){
            for (int j=0; j<n; j++){
                int sup = matrix[i][j]+dp[i-1][j];
                // left up
                int lup = 1e9; if (j-1 >=0) lup= matrix[i][j]+dp[i-1][j-1];
                // Right up
                int rup = 1e9; if (j+1 < n) rup= matrix[i][j]+dp[i-1][j+1];
                dp[i][j] = min({sup,lup,rup});
            }
        }
        int ans=dp[n-1][0];
        for (int i=1; i<n; i++){
            ans=min(ans, dp[n-1][i]);
        }
        return ans;
    }
};