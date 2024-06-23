class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            if (ans%2==1){
                nums[i]^=1;
            }
            if(nums[i]==0){
                ans++;
            }
        }
        return ans;
    }
};
