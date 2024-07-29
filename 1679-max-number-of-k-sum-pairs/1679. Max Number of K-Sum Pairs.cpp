class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int leftptr = 0;
        int rightptr = nums.size() -1 ;
        int removalops = 0;
        while (rightptr>leftptr){
            if (nums[leftptr]+nums[rightptr] < k){
                leftptr++;
            }else if (nums[leftptr]+nums[rightptr] > k){
                rightptr--;
            }else{
                leftptr++;
                rightptr--;
                removalops++;
            }
        }
        return removalops;
    }
};