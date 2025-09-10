class Solution {
public:
    int rec(int index, int days, vector<int>& jobDifficulty, vector<vector<int>>&dp){
        if (days == 1){
            // gotta return the max from index to end;
            int maxd = -1;
            for(int j=index; j<jobDifficulty.size(); j++) maxd = max(maxd, jobDifficulty[j]);
            return maxd;
        }
        if (dp[index][days] != -1) return dp[index][days];
        int result = INT_MAX, maxy = INT_MIN;
        for(int j=index; j<=jobDifficulty.size()-days; j++){
            maxy = max(maxy, jobDifficulty[j]);
            result = min(result, maxy+rec(j+1, days-1, jobDifficulty, dp));
        }
        return dp[index][days] = result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (d>n) return -1;
        vector<vector<int>>dp( n, vector<int>(d+1, -1));
        return rec(0, d, jobDifficulty, dp);
    }
};