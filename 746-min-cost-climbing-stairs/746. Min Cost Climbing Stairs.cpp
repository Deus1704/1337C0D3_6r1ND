class Solution {
public:
    int rec(int index, int costupto, vector<int>&a, vector<int>&dp){
        if (index >= a.size()) return 0;
        if (dp[index]!=-1) return dp[index];
        // climb one step
        int route1 = a[index]+rec(index+1,costupto+a[index],a,dp);
        // climb two steps 
        int route2 = a[index]+rec(index+2,costupto+a[index],a, dp);
        // cout<<"Now at index="<<index<<", we have, r1="<<route1<<", r2="<<route2<<endl;
        return dp[index]=min(route1,route2);
    }
    int minCostClimbingStairs(vector<int>& cost) { 
        vector<int>dp(1001,-1);
        return min(rec(0,0,cost, dp), rec(1,0,cost, dp));
    }
};