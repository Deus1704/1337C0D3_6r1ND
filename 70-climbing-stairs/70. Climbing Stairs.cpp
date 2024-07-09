int rec(int level, int n, vector<int>& memo){
    if (level>n) return 0;
    if (level == n) return 1;
    if (memo[level]!=-1) return memo[level];
    int ans = 0;
    for (auto i=1; i<3; i++){
        if (level+i <= n){
            int way = rec(level+i, n, memo);
            ans+= way;
        }
    }
    memo[level] = ans;
    return ans;
}

class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return rec(0,n, memo);
    }
};