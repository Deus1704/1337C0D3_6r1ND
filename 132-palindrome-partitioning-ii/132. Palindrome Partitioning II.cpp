class Solution {
public:
    bool checkpali(string &s){
        int n=s.size();
        if (n==1) return true;
        else{
            int l=0,r=n-1;
            while (l<r){
                if (s[l]==s[r]){
                    l++;r--;
                }else{
                    return false;
                }
            }
            if (l>=r) return true;
            else return false;
        }
    }
    int rec(int i, string &s, vector<int>&dp, int n){
        // base case;
        if (i==n) return 0;
        string t = "";
        int mincost=INT_MAX;
        if (dp[i]!=-1) return dp[i];
        for (int j=i; j<n; j++){
            t+=s[j];
            if (checkpali(t)){
                // cout<<"Now at t="<<t<<endl;
                int cost = 1+rec(j+1,s,dp,n);
                mincost = min(mincost, cost);
            }
        }
        return dp[i]=mincost;
    }
    int minCut(string &s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return rec(0,s,dp,n)-1;
    }
};