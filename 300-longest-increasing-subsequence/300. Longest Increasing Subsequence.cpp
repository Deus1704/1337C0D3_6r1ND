class Solution {
public:
    int rec(int index, int prev, vector<int>& a, vector<vector<int>>& dp){
        if (index==a.size()) return 0;
        if (dp[index][prev+1]!=-1) return dp[index][prev+1];
        int len = rec(index+1, prev, a ,dp);
        if (prev == -1 || a[index]>a[prev]){
            len = max(len, 1+rec(index+1, index, a, dp));
        }
        return dp[index][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return rec(0,-1,nums,dp);
    }
};