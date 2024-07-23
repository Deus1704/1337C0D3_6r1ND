/// Comparator is noice
bool cmp(pair<int,int>a, pair<int,int>b){
        if (b.second == a.second) return a.first > b.first;
        return b.second > a.second;
    }
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mapp;
        for (auto it:nums){
            mapp[it]++;
        }
        vector<int>ans;
        vector<pair<int,int>>temp; // number and then its frequency
        for (auto& it: mapp){
            temp.push_back({it.first,it.second});
        }
        sort(temp.begin(), temp.end(), cmp);
        for (auto& it : temp){
            for (int j=0; j<it.second; j++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};