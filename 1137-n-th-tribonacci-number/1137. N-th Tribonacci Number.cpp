class Solution {
private:
    int TriFib(int n, int dp[]){
        if (n<=1) return n;
        if (n==2) return 1;
        if (dp[n]) return dp[n];
        return dp[n] = TriFib(n-3,dp)+TriFib(n-2,dp)+TriFib(n-1,dp);
    }
public:
    int tribonacci(int n) {
        int dp[100000];
        memset(dp,0,sizeof(dp));
        return TriFib(n,dp);
    }
};