// This is a TC-O(n*m) solution still yet ts gets accepted over the recursion due to less overhead.
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size(), m = t2.size();
        vector<vector<int>>dp(n+1, (vector<int>(m+1,-1)));
        for (int i=0; i<=n; i++) dp[i][0]=0;
        for (int j=0; j<=m; j++) dp[0][j]=0;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (t1[i-1] == t2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

// ---------------- Below is the recursion based solution. Works but TLE for 1 fucking test case. ---------
// Still TC-O(n*m) & SC- O(n*m)+O(n+m)
// class Solution {
// public:
//     int rec(int i1, int i2, string t1, string t2, vector<vector<int>>&dp){
//         // base case
//         if (i1<0 || i2<0) return 0; // since no sequence possible if we go beyond 0;
//         // cache check
//         if (dp[i1][i2]!= -1) return dp[i1][i2];
//         // check if they match
//         if (t1[i1]==t2[i2]) return dp[i1][i2]=1+rec(i1-1,i2-1,t1,t2, dp);
//         // If they do not match then try the other two possible steps. Finally take the max, save and return
//         return dp[i1][i2]=max(rec(i1-1,i2,t1,t2, dp), rec(i1,i2-1,t1,t2, dp));
//     }
//     int longestCommonSubsequence(string t1, string t2) {
//         vector<vector<int>>dp(t1.size(), (vector<int>(t2.size(),-1)));
//         return rec(t1.size()-1,t2.size()-1,t1,t2, dp);
//     }
// };