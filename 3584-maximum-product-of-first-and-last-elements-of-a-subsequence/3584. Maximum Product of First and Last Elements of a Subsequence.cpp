class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        long long ans=LLONG_MIN;
        if (m==1){
            for (auto &i:nums) ans= max(ans, (long long)i*i);
        }else{
            set<int>temp;
            for (int i=m-1; i<n; i++){
                temp.insert(nums[i-(m-1)]);
                ans = max(ans, (long long)nums[i]*(*(temp.begin())));
                ans = max(ans, (long long)nums[i]*(*(temp.rbegin())));
            }
        }
        return ans;
    }
};