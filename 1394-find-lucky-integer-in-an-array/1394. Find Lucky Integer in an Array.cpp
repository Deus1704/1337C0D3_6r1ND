class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for (auto i:arr) mp[i]++;
        int maxy= -1;
        for (auto i:mp) if (i.first == i.second) maxy=max(maxy, i.first);
        return maxy;
    }
};