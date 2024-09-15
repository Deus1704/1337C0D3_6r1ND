void rec(vector<int>& nums,vector<vector<int>>&ans,vector<int>visited, int index, vector<int>temp){
    // base case when the index is beyond the last
    if (index >= nums.size()){
        ans.push_back(temp);
        return ;
    }
    // pick
    temp.push_back(nums[index]);
    rec(nums,ans,visited,index+1,temp);
    temp.pop_back();
    //not pick
    rec(nums,ans,visited,index+1,temp);
    return ;
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>visited(nums.size(),0);
        vector<int>temp;
        rec(nums,ans,visited,0,temp);
        return ans;
    }
};
