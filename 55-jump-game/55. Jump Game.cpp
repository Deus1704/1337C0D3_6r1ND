class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool can = true; int max_reach = 0, n=nums.size();
        for (int i=0; i<n; i++){
            if (i!=0 && i > max_reach){
                can = false; break;
            }
            max_reach = max(max_reach, i+nums[i]);
        }
        return can;
    }
};