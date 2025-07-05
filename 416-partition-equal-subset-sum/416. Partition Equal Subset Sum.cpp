class Solution {
public:
    bool rec(vector<int>& nums, int i, int target, vector<vector<int>>&dp){
        if (i==nums.size()) return target==0?true:false;
        if (target==0) return true;
        if (target<0) return false;
        if (dp[i][target]!=-1) return dp[i][target];
        return dp[i][target] = rec(nums,i+1, target-nums[i], dp) || rec(nums,i+1, target, dp);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(), s=0; for (auto i:nums) s+=i;
        vector<vector<int>>dp(n+1, vector<int>(s,-1));
        if (s%2!=0) return false;
        if (rec(nums,0, s/2, dp)) return true;
        return false;
    }
};