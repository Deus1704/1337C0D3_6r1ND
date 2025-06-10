#include <bits/stdc++.h>
class Solution {
public:
    int binsearch(vector<int>&t, int target){
        int l=0, r=t.size()-1;
        while (l<r){
            int mid = (l+r)/2;
            if (t[mid]<target){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        for (int i=0; i<n; i++){
            if (i==0 || nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }else{
                int index = binsearch(temp,nums[i]);
                temp[index] = nums[i];
            }
        }
        return temp.size();
    }
};

// The following is TC->O(n^2) and SC->O(n^2)
// class Solution {
// public:
//     int rec(int index, int prev, vector<int>& a, vector<vector<int>>& dp){
//         if (index==a.size()) return 0;
//         if (dp[index][prev+1]!=-1) return dp[index][prev+1];
//         int len = rec(index+1, prev, a ,dp);
//         if (prev == -1 || a[index]>a[prev]){
//             len = max(len, 1+rec(index+1, index, a, dp));
//         }
//         return dp[index][prev+1] = len;
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         return rec(0,-1,nums,dp);
//     }
// };