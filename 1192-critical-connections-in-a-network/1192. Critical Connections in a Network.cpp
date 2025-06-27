bitset<100000>vis;
int tin[100001], low[100001];
//time of insertion, lowest time to reach
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //find edges not part of any cycle
        vector<vector<int>>adj(n);
        for(const auto&v:connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vis.reset();
        memset(tin, -1, n*sizeof(int));
        memset(low, -1, n*sizeof(int));

        vector<vector<int>>ans;
        int time = 0;
        auto dfs = [&](int u, int par, auto&&self)->void{
            vis.set(u);
            low[u] = tin[u] = time++;

            for(const int&v:adj[u]){
                if(v==par)  continue;
                if(!vis[v])
                    self(v, u, self);
                if(low[v]<=tin[u]){
                    //strongly connected
                    low[u] = min(low[u], low[v]);
                }else{
                    ans.push_back({u, v});
                }
            }
        };

        dfs(0, -1, dfs);
        return ans;
    }
};