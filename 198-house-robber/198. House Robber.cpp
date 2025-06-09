class Solution {
public:
    int rec(int i,vector<int>& a, vector<int>& dp ){
        // base
        if (i>= a.size()) return 0;
        // cache check
        if (dp[i]!=-1) return dp[i];
        // check all ways
        int p1=a[i]+rec(i+2,a,dp); // the current house is stolen
        int p2 = rec(i+1, a ,dp); // the current house is not stolen
        // save and return
        return dp[i]=max(p1,p2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        // no need to keep a stolen variable here since in the recursion itself we are returning the max
        return max(rec(0,nums,dp),rec(1,nums,dp));
    }
};