class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pq) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for (auto &i:pq){
            adj[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        int index=0;
        queue<int>q;for (int i=0; i<n; i++) if (!indeg[i]) q.push(i);
        while (!q.empty()){
            int f = q.front(); q.pop();
            index++;
            for (auto i:adj[f]){
                indeg[i]--;
                if (!indeg[i]) q.push(i);
            }
        }
        if (index!=n) return false;
        return true;
    }
};