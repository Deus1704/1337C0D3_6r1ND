class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>f; for(auto &i:nums) f[i]++;
        if (f.size() == 1)return 0;
        return 1;
    }
};