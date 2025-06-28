class Solution {
public:
    void rec(int i, int k, vector<int>& n,vector<pair<int,vector<int>>>&ans, vector<int>&temp ){
        if (i== n.size() ){
            if (temp.size()==k){
                int summ = 0; for (auto i:temp) summ+=i;
                ans.push_back({summ, temp});
            }
            return ;
        }
        // take
        temp.push_back(n[i]);
        rec(i+1, k, n, ans, temp);
        // not take
        temp.pop_back(); rec(i+1, k, n, ans, temp);
        return ;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        if (k==nums.size()) return nums;
        int n = nums.size();
        vector<pair<int,vector<int>>>an; vector<int>temp;
        // rec(0, k, nums, an, temp);
        // sort(an.begin(), an.end(), [](auto a, auto b){
        //     return a.first>b.first;
        // });
        // return an[0].second;
        vector<pair<int,int>>mp; // first value, then index;
        for (int i=0; i<n; i++){
            mp.push_back({nums[i], i});
        }
        sort(mp.begin(), mp.end());
        vector<pair<int,int>>ans;
        for (int i=n-1; i>n-k-1; i--){
            ans.push_back({mp[i].first, mp[i].second});
        }
        sort(ans.begin(), ans.end(), [](auto a, auto b){
            return a.second<b.second;
        });
        vector<int>fin; for (auto i:ans) fin.push_back(i.first);
        // reverse(ans.begin(),ans.end());
        return fin;
    }
};