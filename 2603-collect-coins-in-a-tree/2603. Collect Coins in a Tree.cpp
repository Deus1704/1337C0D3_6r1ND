class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        vector<int>indeg(n);
        for (auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++; indeg[i[1]]++;
        }
        queue<int>q;
        // first removing the leaf nodes with 0 coins
        for (int i=0; i<n; i++){
            if (!coins[i] && indeg[i]==1) q.push(i);
        }
        while (!q.empty()){
            int node = q.front(); q.pop();
            for (auto &v:adj[node]){
                if (indeg[v]) {indeg[v]--; if (indeg[v]==1 && !coins[v]) q.push(v);}
            }
            indeg[node] = 0;
        }
        // now need to bring the leaf nodes containing the coins 2 levels up, so that it becomes easy to count
        for (int i=0; i<2; i++){
            for (int j=0; j<n; j++){
                if (indeg[j]==1) q.push(j);
            }
            while (!q.empty()){
                int node = q.front(); q.pop();
                for (auto &v:adj[node]){
                    if (indeg[v]) indeg[v]--;
                }
                indeg[node]=0;
            }
            for (auto &i:indeg) cout<<i<<","; cout<<endl;
        }
        int ans=0;
        for (auto &i:edges){
            if (indeg[i[0]] && indeg[i[1]]) ans++;
        }
        return ans*2;
    }
};