class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(), len_max_lis=1;
        vector<int>dp(n,1), counts(n,1);

        for (int i=0; i<n; i++){
            for (int prev=0; prev<i; prev++){
                if (nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                    dp[i]=dp[prev]+1;
                    counts[i]=counts[prev];
                }else if(nums[prev]<nums[i] && (1+dp[prev]==dp[i])){
                    counts[i]+=counts[prev];
                }
            }
            len_max_lis = max(len_max_lis , dp[i]);
        }
        cout<<len_max_lis<<endl;
        int count=0;
        for (int i=0; i<n; i++){
            if (len_max_lis==dp[i]){
                // cout<<"Now at i="<<i<<", dp[i]="<<dp[i]<<endl;
                count+=counts[i];
                // cout<<"New count="<<count<<endl;
            }
        }
        return count;
    }
};