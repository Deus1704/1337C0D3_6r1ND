class Solution {
public:
    int rec(int i, int n, vector<int>& arr, int k, vector<int>&dp){
        if (i==n) return 0;
        if (dp[i]!=-1) return dp[i];
        int len=0,maxy=-1, summ=0, maxans=INT_MIN;
        for (int j=i; j<min(n,i+k); j++){
            len++; maxy=max(maxy, arr[j]);
            summ= len*maxy + rec(j+1,n,arr,k,dp);
            maxans= max(maxans, summ);
        }
        return dp[i]=maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return rec(0,n,arr,k,dp);
    }
};