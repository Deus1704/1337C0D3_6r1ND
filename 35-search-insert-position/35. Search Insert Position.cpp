class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid=0,l=0,n=nums.size(),r=n;
        if (target>nums[n-1]) return n;
        while (l<=r){
            mid = (l+r)/2;
            if (nums[mid]==target) return mid;
            else{
                if (nums[mid]>target){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
        }
        return l;
    }
};