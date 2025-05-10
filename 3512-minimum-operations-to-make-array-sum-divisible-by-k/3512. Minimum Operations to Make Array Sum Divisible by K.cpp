class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cur_sum = accumulate(nums.begin(),nums.end(), 0);
        if (cur_sum%k==0) return 0;
        else{
            return cur_sum%k;
        }
    }
};