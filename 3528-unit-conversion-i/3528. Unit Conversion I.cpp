class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();
        long long MOD = 1000000000+7;
        vector<vector<pair<long long,long long>>>adj(n+1);
        for (auto &i:conversions){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>vals(n+1,-1);vals[0]=1;
        queue<long long>q; q.push(0);
        while (!q.empty()){
            long long toppy = q.front(); q.pop();
            for (auto [v,f]:adj[toppy]){
                if (vals[v]==-1){
                    vals[v] = ( (vals[toppy]) * (f) )%MOD;
                    q.push(v);
                }
            }
        }
        return vals;
    }
};