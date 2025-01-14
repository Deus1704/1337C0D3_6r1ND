class Solution {
public:
    void rec(vector<int>& nums, int target, int index, vector<int> t, set<vector<int>>& temp){
        if (index >= nums.size() or target<0){
            if (target == 0) temp.insert(t);
            return;
        }
        // pick and stay
        target-=nums[index]; t.push_back(nums[index]);
        rec(nums,target,index, t, temp);
        // not pick
        target+=nums[index];t.pop_back();
        rec(nums,target,index+1, t, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> temp;
        vector<int> t;
        rec(nums,target,0, t, temp);
        vector<vector<int>> ans(temp.begin(),temp.end());
        return ans;
    }
};
