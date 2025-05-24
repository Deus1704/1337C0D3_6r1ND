class Solution {
public:
    long long power(long long b, long long e) {
        long long res = 1;
        long long MOD = 1000000007; 
        b %= MOD;
        while (e > 0) {
            if (e % 2 == 1) {
                res = (res * b) % MOD;
            }
            b = (b * b) % MOD;
            e /= 2;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1; vector<vector<int>>adj(n+1);
        for (auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<pair<int,int>>q; q.push({1,0});
        vector<bool> visited(n + 1, false);
        visited[1]=1;
        int max_path_lt = -1;
        while (!q.empty()){
            const auto [node,dep] = q.front(); q.pop();
            max_path_lt = max(max_path_lt, dep);
            for (auto v:adj[node]){
                if (!visited[v]){
                    visited[v] = true;
                    q.push({v,dep+1});
                }
            }
        }
        return power(2, max_path_lt-1);
    }
};