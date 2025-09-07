class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0 ,an=-1, high = nums.size()-1;
        if (nums.size() == 1 && target == nums[0]) return {0,0};
        while(low<=high){
            int mid = (low+high+1)/2;
            if (nums[mid] == target){
                an=mid; 
                high = mid-1;
            }
            if (nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        int low2=0, ans= nums.size(); high = nums.size()-1;
        while(low2<=high){
            int mid = (low2+high+1)/2;
            if (nums[mid] > target){
                ans=mid;
                high = mid-1;
            }else{
                low2 = mid+1;
            }
        }
        if (an != -1 && ans != -1) return {an, ans-1};
        return {-1,-1};
    }
};