class Solution {
public:
    int rec(int i, int j, vector<int>&a, vector<vector<int>>&dp ){
        // base case;
        if (i>j) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int max_cost = INT_MIN;
        for (int index=i; index<=j; index++){
            int cost = a[i-1]*a[index]*a[j+1] + rec(i,index-1, a,dp) + rec(index+1,j, a,dp);
            max_cost = max(max_cost, cost);
        }
        return dp[i][j]=max_cost;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return rec(1,n-2, nums,dp);
    }
};