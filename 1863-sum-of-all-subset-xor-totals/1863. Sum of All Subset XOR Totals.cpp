void xorit(vector<int>& nums, int& sum, int index, vector<int>ds){
    if (index >= nums.size()){
        int temp = 0;
        for (auto it:ds){
            temp^=it;
        }
        sum += temp;
        return;
    }
    //take
    ds.push_back(nums[index]);
    xorit(nums,sum, index+1, ds);
    ds.pop_back();
    //not take
    xorit(nums,sum, index+1, ds);
}

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int>ds;
        int sum = 0;
        xorit(nums,sum, 0, ds);
        return sum;
    }
};