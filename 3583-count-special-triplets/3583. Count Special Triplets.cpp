class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n= nums.size();
        map<int,vector<int>>mp;
        for (int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int MOD = 1e9+7;
        int count=0;
        for (int i=0; i<n; i++){
            int to_find = nums[i]*2;
            if (mp[to_find].size()>=2){
                auto lb = lower_bound(mp[to_find].begin(), mp[to_find].end(), i), ub = upper_bound(mp[to_find].begin(), mp[to_find].end(), i);
                if (lb != mp[to_find].begin() && ub != mp[to_find].end()) count+= ((lb-mp[to_find].begin())%MOD)*((mp[to_find].end()-ub)%MOD)%MOD ; count%=MOD;
            }
        }
        return count%MOD;
    }
};