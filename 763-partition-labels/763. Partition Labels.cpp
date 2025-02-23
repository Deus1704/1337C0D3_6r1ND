class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int,vector<int>>mp;
        for (int i=0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        vector<pair<int,int>>final_pos;
        for (auto &i:mp){
            final_pos.push_back({i.second.front(),i.second.back()});
        }
        for (auto &i:final_pos) cout<<i.first<<" "<<i.second<<endl;
        sort(final_pos.begin(), final_pos.end());
        vector<pair<int,int>>mkc;
        mkc.push_back(final_pos[0]);
        for (int i=1; i<final_pos.size(); i++){
            if (final_pos[i].first > mkc.back().second ){
                mkc.push_back(final_pos[i]);
            }else{
                mkc.back().second = max(mkc.back().second, final_pos[i].second);
            }
        }
        vector<int>ans;
        for (auto &i:mkc) ans.push_back(i.second-i.first +1 );
        return ans;
    }
};