class Solution {
public:
    int rec(int i, vector<int>&a, vector<int>&dp){
        // base case
        if ( i>=a.size())  return 0;
        // cache check
        if (dp[i]!=-1) return dp[i];
        // all cases;
        int p1 = a[i]+rec(i+2, a,dp);
        int p2 = rec(i+1, a, dp);
        // save and return
        return dp[i]=max(p1,p2);
    }
    int rob(vector<int>& nums) {
        vector<int>dp1(101,-1),dp2(101,-1);
        if (nums.size()==1) return nums[0];
        vector<int>t1,t2;int n=nums.size();
        for (int i=0; i<n; i++){
            if (i!=0)t2.push_back(nums[i]);
            if (i!=n-1) t1.push_back(nums[i]);
        }
        return max(rec(0,t1,dp1), rec(0,t2,dp2));
    }
};