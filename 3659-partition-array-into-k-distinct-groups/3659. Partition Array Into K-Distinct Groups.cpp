class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        map<int,int>mp; for(auto &i:nums) mp[i]++;
        int n = nums.size(); int each_group_freq = n/k; if (n%k!=0) return false;
        for (auto &i:mp) if (i.second > each_group_freq) return false;
        return true;
    }
};