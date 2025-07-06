class Solution {
public:
    bool isvalid(string s){
        if (!s.size()) return false;
        for (auto i:s) if (!isalnum(i) && i!='_') return false;
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        map<string, vector<string>>mp;
        set<string>fuckery={"electronics", "grocery", "pharmacy", "restaurant"};
        for (int i=0; i<n; i++){
            if(isvalid(code[i]) && isActive[i] && fuckery.find(businessLine[i])!=fuckery.end() ){
                // cout<<"Got a valid="<<code[i]<<endl;
                mp[businessLine[i]].push_back(code[i]);
            }
        }
        vector<string>ans;
        for (auto it:mp) {
            // cout<<"now printing codes for business="<<it.first<<": "; 
            sort(it.second.begin(), it.second.end());
            for (auto str:it.second) ans.push_back(str);
        }
        return ans;
    }
};