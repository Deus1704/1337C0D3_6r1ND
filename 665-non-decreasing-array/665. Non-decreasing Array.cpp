class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ops=1, index=1, n=nums.size();
        for (int i=0; i<n-1; i++){
            if (nums[i]<=nums[i+1]) continue;
            if (nums[i]>nums[i+1] && !ops) return false;
            // left decreasing works mostly
            if (nums[i]>nums[i+1]){
                if (i==0 || nums[i+1] >= nums[i-1]){
                    nums[i] = nums[i+1];
                }else{
                    nums[i+1] = nums[i];
                }
                ops--;
            }
        }
        return true;
    }
};