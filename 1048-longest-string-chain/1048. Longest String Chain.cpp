class Solution {
public:
    bool difbychar(string &s1,string &s2 ){
        if (s1.size() != s2.size()+1) return false;
        int first=0, second =0;
        while (first!=s1.size()){
            if (second <= s2.size() && s1[first]==s2[second]){
                first++;second++;
            }else{
                first++;
            }
        }
        if (first==s1.size() && second == s2.size()) return true;
        else return false;
    }
    // since we just need to sort by the length and not its total value.
    static bool comp(string &s1, string &s2){// This needs to be static here since this comparator, has an extra Solution this pointer that is not needed by the standard sort() func. 
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size(), ans = 0;
        sort(words.begin(), words.end(), comp);
        vector<int>dp(n,1);
        for (int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (difbychar(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i] = 1+dp[j];
                }
            }
            if (dp[i]>ans) ans = dp[i];
        }
        return ans;
    }
};