class Solution {
public:
    int rec(int i, int j, vector<int>& cts, vector<vector<int>>&dp){
        // base
        if (i>j) return 0;
        // cache check
        if (dp[i][j]!=-1) return dp[i][j];
        // try all possible cuts;
        int mini = 1e9;
        for (int index = i; index<=j; index++){
            mini = min(mini, cts[j+1]-cts[i-1]+rec(i,index-1, cts, dp)+rec(index+1, j, cts, dp));
            
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cts) {
        int m = cts.size();sort(cts.begin(),cts.end());
        cts.push_back(n);cts.insert(cts.begin(),0);
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return rec(1,m, cts, dp);
    }
};