class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m,0));
        // Set the base cases
        for (int i=0; i<n; i++) dp[i][0] = matrix[i][0];
        for (int i=0; i<m; i++) dp[0][i] = matrix[0][i];

        // Now at every other if the bottom-right can be joined with an earlier square, count the min
        for (int i=1; i<n; i++){
            for (int j=1; j<m; j++){
                if (matrix[i][j]){
                    // Check the matrices that are being completed by up, diagonal, and previous
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                }
            }
        }
        int ans = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (dp[i][j]) ans+=dp[i][j];
            }
        }
        return ans;
    }
};