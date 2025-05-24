class Solution {
public:
    int maxSubstrings(string word) {
        int n=word.size();
        if (n<4) return 0;
        vector<int>dp(n+1,0);
        vector<int> best_prev_val(26,-1);
        for (int i=1; i<=n ;i++){
            dp[i]=dp[i-1];
            if (i>=4){
                char first = word[i - 4];
                int j = first - 'a'; 
                int dp_val_before_psi = dp[i - 4]; 
                best_prev_val[j] = 
                max(best_prev_val[j], dp_val_before_psi);
                char ce = word[i - 1];
                int end_index = ce - 'a';
                int max_dp = best_prev_val[end_index];
                if (max_dp != -1) {
                    dp[i] = max(dp[i], max_dp + 1);
                }
            }
        }
        return dp[n];
    }
};