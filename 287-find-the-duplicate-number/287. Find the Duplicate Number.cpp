class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ptr=0, n=nums.size();
        for (int i=0; i<n; i++){
            if (nums[abs(nums[i])] <0 ){
                // found the repeated number
                ptr = i;
                break;
                // return abs(nums[abs(nums[i])]);
            }else{
                nums[abs(nums[i])] *= -1;
            }
        }
        for (auto &i:nums) if (i<0) i*=-1;
        return nums[ptr];
    }
};