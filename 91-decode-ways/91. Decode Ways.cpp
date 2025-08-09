class Solution {
public:
    int rec(int index, string &s, map<string, char>&mp, vector<int>&dp){
        // base case;
        if (index == s.size()) return 1;
        if (index>s.size()) return 0;
        if (s[index]=='0') return 0;
        if (dp[index]!=-1) return dp[index];
        int ways = 0;
        if(s[index] != '0'){
            ways += rec(index+1, s, mp,dp) + (( (s[index]<='2' && s[index+1]<'7') || (s[index]<='1'))?rec(index+2, s, mp,dp):0);
        }
        return dp[index] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        int ptr = 0;
        while (s[ptr] == '0') {ptr++; break;}
        if (ptr) return 0;
        map<string, char>mp;
        vector<int>dp(n,-1);
        for (int i=1; i<=26; i++){
            mp[to_string(i)] = 'A'+(i-1);
        }
        return rec(0, s, mp, dp);
    }
};