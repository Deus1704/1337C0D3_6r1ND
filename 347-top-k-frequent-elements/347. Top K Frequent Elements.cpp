class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for (auto &i:nums){
            mp[i]++;
        }
        vector<pair<int, int>>ranks;
        for (auto &i:mp){
            ranks.push_back({i.second, i.first});
        }
        for (auto &i:ranks) cout<<"The i.first="<<i.first<<" and i.second="<<i.second<<endl;
        sort(ranks.rbegin(), ranks.rend());
        for (auto &i:ranks) cout<<"The i.first="<<i.first<<" and i.second="<<i.second<<endl;
        vector<int> ans;
        for (int i=0; i<k; i++){
            ans.push_back(ranks[i].second);
        }
        return ans;
    }
};