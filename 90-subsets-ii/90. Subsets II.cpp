class Solution {
    private:
        void rec(vector<int>&nums, set<vector<int>>&s, vector<int>temp, int index){
            if (index >= nums.size()){
                sort(temp.begin(), temp.end());
                s.insert(temp);
                return;
            }
            // Take
            temp.push_back(nums[index]);
            rec(nums, s, temp, index+1);
            // Not Take
            temp.pop_back();
            rec(nums, s, temp, index+1);
        }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>temp;
        rec(nums, s, temp, 0);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
