class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ptr=-1; int n = nums.size();
        for (int i=n-2; i>=0 ;i--){
            if (nums[i] < nums[i+1]){
                ptr = i; break;
            }
        }
        if (ptr == -1){
            reverse(nums.begin(), nums.end()); return ;
        }
        int to_swap = -1;
        for (int i=n-1; i>ptr ; i--){
            if (nums[ptr] < nums[i]){
                to_swap = i; break;
            }
        }
        swap(nums[ptr], nums[to_swap]);
        // now just reverse the remaining part
        reverse(nums.begin()+ptr+1, nums.end());
    }
};