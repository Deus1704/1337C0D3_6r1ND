class Solution {
public:
    int findMin(vector<int> &nums) {
        int cur_min = nums[0];
        int low=0, high = nums.size()-1;
        while (low<=high){
            // if at any point if the sub array in range of search is sorted then just return the leftmost value.
            if (nums[low]<nums[high]){
                cur_min = min(cur_min, nums[low]);
            }
            int mid = (low+high)/2;
            cur_min = min(cur_min, nums[mid]);
            cout<<"the cur_min ="<<cur_min<<" and the l="<<nums[low]<<" , h="<<nums[high]<<" and mid is at="<<nums[mid]<<endl;
            if (nums[mid] >= nums[low]){
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return cur_min;
    }
};
