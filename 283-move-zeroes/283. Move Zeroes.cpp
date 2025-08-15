class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0, n=nums.size(), right = 0;
        while (right<n){
            if(nums[right]!=0){
                swap(nums[right], nums[left]); left++;
            }
            right++;
        }
    }
};