class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<int>&visited, int &vertices,vector<int>&t ){
        visited[i]=1;vertices++;t.push_back(i);
        for (auto node:adj[i]){
            if (!visited[node]) {
                dfs(node,adj,visited, vertices,t);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        vector<vector<int>>adj(n);
        for (auto i:c){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>visited(n); int count=0, extra=0;
        for (int i=0; i<n; i++){
            if (!visited[i]){
                int vertices=0, edges=0;
                vector<int>temp;
                dfs(i,adj,visited, vertices, temp);
                // cout<<"now printing temp=";
                // for(auto j:temp)cout<<j<<","; cout<<endl;
                // find_edges(adj,temp);
                for (auto j:temp) edges+=adj[j].size();
                extra+= edges/2-(vertices-1);
                // cout<<"We had vertices="<<vertices<<", and extra="<<extra<<endl;
                count++;
            }
        }
        if (extra>=count-1) return count-1;
        return -1;
    }
};