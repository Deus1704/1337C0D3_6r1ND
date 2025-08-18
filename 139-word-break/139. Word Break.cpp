class Solution {
public:
    bool rec(string s, int l, map<string,int>&mp, vector<int>&dp){
        if (l==s.size()){
            return true;
        }
        if (dp[l] != -1) return dp[l];
        for (int i = l; i<s.size(); i++){
            string temp = s.substr(l, i-l+1); 
            // cout<<"Trying temp="<<temp<<endl;
            if (mp.find(temp) != mp.end()){
                // Then a split is possible here, check further
                if (rec(s, i+1,mp, dp)) return dp[l]=true;
            }
        }
        return dp[l]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mp; vector<int>dp(s.size()+1, -1);
        for (auto &i:wordDict) mp[i]++;
        return rec(s, 0,mp, dp);
    }
};