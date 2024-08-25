class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--){
            int min_index = -1;
            int minVal = INT_MAX;
            for (int i =0; i<nums.size(); i++){
                if (minVal > nums[i]){
                    minVal = nums[i]; min_index = i;
                }
            }
            nums[min_index]*= multiplier;
        }
        return nums;
    }
};