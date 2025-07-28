class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long ans=0; int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=n-2; i>=n/3; i-=2){
            ans+=nums[i];
        }
        return ans;
    }
};