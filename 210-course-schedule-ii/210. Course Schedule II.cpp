class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pq) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for (auto i:pq){
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        vector<int>ans;int index=0;
        queue<int>q; for (int i=0; i<n; i++) if (!indeg[i]) q.push(i);
        while (!q.empty()){
            int node = q.front(); q.pop();
            index++;ans.push_back(node);
            for (auto neigh:adj[node]){
                indeg[neigh]--;
                if (!indeg[neigh]) q.push(neigh);
            }
        }
        if (index!=n) return {};
        return ans;
    }
};