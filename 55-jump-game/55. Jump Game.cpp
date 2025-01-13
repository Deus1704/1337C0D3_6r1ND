class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index_max_reached=0; int cur_index=0;
        if (nums[0]==0 && nums.size()>1) return false;
        for (int i=0; i<nums.size()-1; i++){
            // cout<<"Now the max possible reach="<<index_max_reached<<" and cur_index="<<cur_index<<endl;
            if (nums[i]==0 && index_max_reached<=i ) break;
            index_max_reached = max(index_max_reached, cur_index+nums[i]);
            cur_index++;
        }
        // cout<<"Now the max possible reach="<<index_max_reached<<" and cur_index="<<cur_index<<endl;
        if (index_max_reached >= nums.size()-1) return true;
        else return false;
    }
};