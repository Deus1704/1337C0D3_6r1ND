class Solution {
    void bfs(vector<vector<int>>&adj, vector<int>&visited, int root, int &count_province){
        queue<int>q;q.push(root);
        if (visited[root]==1) return;
        visited[root]=1;
        while (!q.empty()){
            int top_node = q.front(); q.pop();
            for (auto &i:adj[top_node]){
                if (visited[i]==0) {
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
        count_province++;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>adj(isConnected.size()+1);
        for (int i=1; i<=isConnected.size(); i++){
            for (int j=0; j<isConnected[i-1].size(); j++){
                if (isConnected[i-1][j] && i!=j+1){
                    adj[i].push_back(j+1);
                }
            }
        }
        // Now using BFS on all the nodes to get the total number of provinces
        vector<int>visited(isConnected.size()+1, 0); int count_province=0;
        for (int i=1; i<=isConnected.size(); i++){
            bfs(adj,visited, i, count_province);
        }
        return count_province;
    }
};