class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int ans=0;
        for (int i=nums.size()-1; i>=0; i--){
            int start = max(0, i-nums[i]);
            while (start<=i) {
                ans+=nums[start];
                start++;
            }
        }
        return ans;
    }
};