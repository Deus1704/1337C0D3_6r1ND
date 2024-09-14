// int binarysearch(vector<int>&nums, int target, int low, int high){
//     if (low>high){
//         return -1;
//     }
//     int mid = (low+high)/2;
//     if (nums[mid]==target) return mid;
//     else if (nums[mid]>target){
//         return binarysearch(nums,target,low,mid-1);
//     }else{
//         return binarysearch(nums,target,mid+1,high);
//     }
// }

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         return binarysearch(nums,target,0,nums.size()-1);
//     }
// };
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if (nums[mid]==target) return mid;
            else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
};