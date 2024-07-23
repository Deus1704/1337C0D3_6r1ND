bool cmp(pair<char,int>a,pair<char,int>b){
    return a.second>b.second;
}
class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mapp;
        for (auto ch:s){
            mapp[ch]++;
        }
        string ans = "";
        vector<pair<char,int>>temp;
        for (auto& it:mapp){
            temp.push_back({it.first,it.second});
        }
        sort(temp.begin(),temp.end(),cmp);
        for (auto& it:temp){
            ans+= string(it.second, it.first);
        }
        return ans;
    }
};