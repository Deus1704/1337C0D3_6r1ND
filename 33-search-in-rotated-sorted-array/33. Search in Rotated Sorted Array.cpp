class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (nums[mid]== target) return mid;
            cout<<"Now at mid="<<mid<<" and l="<<l<<" and r="<<r<<endl;
            if ( nums[mid]>=nums[l]){ // this checks if left sorted
                if (nums[l]<=target && nums[mid]>=target) r=mid-1;
                else l = mid+1;
            }else{ // this checks if right sorted
                if (nums[mid]<=target && target<=nums[r]) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};