void rec(vector<int>& nums, int sum, int target, int index, int &ans){
    // base case;
    // cout<<"at index="<<index<<" the sum ="<<sum<<" and the ans ="<<ans<<endl;
    if (index >= nums.size()){
        if (sum == target){
            ans++;
        }
        return ;
    }
    // multiply by '+' and explore possibilities;
    sum += nums[index];
    rec(nums, sum, target, index+1, ans);
    // index-=1;
    sum -= 2*nums[index];
    // multiply by '-' and explore.
    // sum -= nums[index];
    // index+=1;
    rec(nums, sum, target, index+1, ans);

}


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        int sum = 0;
        int index = 0;
        rec(nums, sum, target, index, ans);
        return ans;
    }
};