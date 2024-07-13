class Solution {
private:
    void dfs(vector<int> adjList[], int node, vector<int>& visited){
        visited[node] = 1;
        for (auto it : adjList[node]){
            if (!visited[it]){
                dfs(adjList, it, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjList[n];
        for (int i =0; i< n;i++){
            for (int j=0; j<n;j++){
                if (isConnected[i][j] && i!=j){
                    adjList[i].push_back(j);
                }
            }
        }
        vector<int> visited(n,0);
        int count=0;
        for (int i =0; i< n; i++){
            if (!visited[i]){
                dfs(adjList, i, visited);
                count++;
            }
        }
        return count;
    }
};