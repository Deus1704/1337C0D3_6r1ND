// TC -> O(N+N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(), maxy=0,l=0,r=0, zero_count=0;
        while (r<n){
            if (nums[r]==0)  zero_count++;
            while ( zero_count> k){
                if (nums[l]==0) zero_count--; // this is necessary since if its not 0 then do not decrease the count
                l++;
            }
            if ( zero_count<= k ){
                maxy=max(maxy, r-l+1);
                r++;
            } 
        }
        return maxy;
    }
};