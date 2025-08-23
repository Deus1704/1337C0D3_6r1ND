class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), cur_sum=nums[0], maxy = nums[0];
        for (int i=1; i<n; i++){
            cur_sum = max(nums[i], cur_sum+nums[i]);
            maxy = max(maxy , cur_sum);
        }
        return maxy;
    }
};