class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int> indeg(n), ans;
        for (int i=0; i<n; i++){
            for (auto j:graph[i]){
                adj[j].push_back(i);
                indeg[i]++;
            }
        }
        // for (auto i:adj) {cout<<"this node has="; for (auto j:i) cout<<j<<","; cout<<endl;}
        queue<int>q; for (int i=0; i<n; i++) if (!indeg[i]) q.push(i);
        while (!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            for (auto j:adj[node]){
                indeg[j]--;
                if (!indeg[j]) q.push(j);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};