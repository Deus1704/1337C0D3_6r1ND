class Solution {
public:
    int rec(int index, vector<int>& nums1, vector<int>& nums2, int mask ,vector<vector<int>>&dp){
        // base case, if reached the end of the array then all pairings have been done, and nothing left to do.
        if (index == nums1.size()) return 0;
        if (dp[index][mask] != -1) return dp[index][mask];
        int min_xor_sum = INT_MAX;
        // try for this index all the available 
        for(int i=0; i<nums1.size(); i++){
            if ( (mask&(1<<i)) == 0){
                // used[i] = true;
                // mask += (1<<i);
                min_xor_sum = min(min_xor_sum, (nums1[index]^nums2[i]) + rec(index+1, nums1, nums2, mask^(1<<i), dp));
                // used[i] = false; // for backtracking
                // mask -= (1<<i);
            }
        }
        return dp[index][mask] = min_xor_sum;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        // vector<int>used(n); // Using simple array for the tracking of the current state
        vector<vector<int>>dp(n, vector<int>(500000, -1));
        return rec(0, nums1, nums2, 0 , dp);
    }
};