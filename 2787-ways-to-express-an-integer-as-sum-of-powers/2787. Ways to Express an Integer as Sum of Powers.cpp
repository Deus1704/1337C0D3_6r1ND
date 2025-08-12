int MOD = 1000000007;
class Solution {
public:
    int pow(int base, int exp, int MOD){
        base%=MOD;
        long long result = 1;
        while (exp){
            if (exp&1) result = (result*base)%MOD;
            base = (base*base)%MOD;
            exp>>=1;
        }
        return (int)result;
    }
    int find_number_of_subsequences_with_sum_n(int index, int target_sum, vector<int>&arr, vector<vector<int>>&dp){
        if (index >= arr.size()) {if (target_sum==0) return 1; else return 0;}
        if (target_sum == 0) return 1;
        // cache check
        if (dp[index][target_sum] != -1){
            // This means its already pre-computed, then simply use this value;
            return dp[index][target_sum];
        }
        // pick 
        int pick_ways = target_sum-arr[index]>=0 ? find_number_of_subsequences_with_sum_n(index+1, target_sum-arr[index], arr, dp):0;
        // not pick
        int not_pick_ways = find_number_of_subsequences_with_sum_n(index+1, target_sum, arr, dp);
        return dp[index][target_sum] = (pick_ways%MOD+not_pick_ways%MOD)%MOD;
    }
    int numberOfWays(int n, int x) {
        vector<int>arr;
        int ctr=1;
        while (pow(ctr,x,MOD) <= n){
            arr.push_back(pow(ctr,x,MOD)); ctr++;
        }
        // for(auto &i:arr) cout<<i<<","; cout<<endl;
        vector<vector<int>>dp(arr.size(), vector<int>(n+1,-1));
        int ways = find_number_of_subsequences_with_sum_n(0, n, arr, dp);
        return ways%MOD;
        // return 0;
    }
};