class Solution {
public:
    int rec(vector<int>& coins, int amount, int index, int count, vector<vector<int>>&dp){
        if (index == coins.size()) {
            if (amount ==0 ) return 0;
            return 1e9;
        }
        if (dp[index][amount]!=-1) return dp[index][amount]; 
        // take & stay
        int stay=1e9, move=1e9, ntmove = 1e9;
        if (amount-coins[index]>=0){
            stay = 1+rec(coins,amount-coins[index], index, count+1,dp );
        }
        // take & move
        if (amount-coins[index]>=0){
            move = 1+rec(coins,amount-coins[index], index+1, count+1, dp);
        }
        // Not Take and Move
        ntmove = rec(coins, amount, index+1, count, dp);
        return dp[index][amount]=min({stay, move, ntmove});
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        int ans = rec(coins, amount, 0, 0, dp);
        return ans==1e9? -1:ans;
    }
};