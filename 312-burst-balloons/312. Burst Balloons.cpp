class Solution {
public:
    int rec(int i, int j,vector<int>& a,vector<vector<int>>& dp ){
        // base case
        if (i>j) return 0;
        // cache check
        if (dp[i][j]!=-1) return dp[i][j];
        // try all cases
        int maxy = INT_MIN;
        for (int index=i; index<=j; index++){
            int coin = a[i-1]*a[index]*a[j+1] + rec(i,index-1,a,dp)+rec(index+1,j,a,dp);
            maxy=max(maxy, coin);
        }
        return dp[i][j]=maxy;
    }
    int maxCoins(vector<int>& a) {
        a.push_back(1);a.insert(a.begin(),1);
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return rec(1,n-2,a,dp);
    }
};