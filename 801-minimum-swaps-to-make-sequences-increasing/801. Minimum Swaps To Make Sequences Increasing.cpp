class Solution {
public:
    int rec(vector<int>& nums1, vector<int>& nums2, int index, int prev_swapped, vector<vector<int>>&dp){ // Rec -> returns the minimum swaps needed to make the arrays inc  
        if (index == nums1.size()){
            // reached the end and hence no need to even swap
            return 0;
        }
        if (dp[index][prev_swapped] != -1) return dp[index][prev_swapped];
        int just_in_swaps=INT_MAX;
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        if (prev_swapped) swap(prev1, prev2);
        if (nums1[index] > prev1 && nums2[index]>prev2){
            just_in_swaps = rec(nums1, nums2, index+1, 0,dp);
        }
        if (nums1[index] > prev2 && nums2[index]>prev1){
            just_in_swaps = min(just_in_swaps, 1+rec(nums1, nums2, index+1, 1, dp));
        }
        return dp[index][prev_swapped] = just_in_swaps;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int ptr=1, n=nums1.size(), swaps=0;
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        // Greedy idea will fail to get the global minimum values of swaps
        // Failing case: 
        //                nums1 = [0,4,4,5,9]
        //                nums2 = [0,1,6,8,10]
        // while (ptr<n){
        //     if(nums1[ptr]>nums1[ptr-1] && nums2[ptr]>nums2[ptr-1]) continue;
        //     else if (nums1[ptr]<=nums1[ptr-1] || nums2[ptr]<=nums2[ptr-1]){
        //         swap(nums1[ptr], nums2[ptr]); swaps++;
        //     }
        //     ptr++;
        // }
        return rec(nums1, nums2, 1, 0, dp);
        
    }
};