class Solution {
public:
    string findValidPair(string s) {
        unordered_map<int,int>mp;
        for (auto &i:s){
            mp[i-'0']++;
            // cout<<i-'0'<<endl;
        }
        string ans="";
        for (int i=1; i<s.size(); i++){
            if ((s[i-1]-'0')== mp[s[i-1]-'0']  && (s[i]-'0') == mp[s[i]-'0']   && s[i-1]!=s[i]){
                cout<<"Here at i="<<i<<" And the matches are s[i-1]="<<s[i-1]<<" and s[i]"<<s[i]<<endl;
                ans.push_back(s[i-1]);
                ans.push_back(s[i]);
                break;
            }
        }
        return ans;
    }
};