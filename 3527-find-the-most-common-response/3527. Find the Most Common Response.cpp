class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        vector<vector<string>> temp;
        for (int i=0; i<responses.size(); i++){
            set<string>s(responses[i].begin(),responses[i].end());
            vector<string>inter(s.begin(), s.end());
            temp.push_back(inter);
        }
        map<string,int>mp;
        for (int i=0; i<temp.size(); i++){
            for (int j=0; j<temp[i].size(); j++){
                mp[temp[i][j]]++;
            }
        }
        int maxy = INT_MIN; string ans;
        for (auto &i:mp){
            if (i.second>maxy){
                maxy = i.second;
                ans = i.first;
            }
        }

        return ans;
    }
};