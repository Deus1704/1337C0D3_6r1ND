void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j, vector<int>delR, vector<int>delC){
    visited[i][j] = 1;
    for (int k =0; k<4; k++){
        if (i+delR[k] < grid.size() && i+delR[k] >=0 && j+delC[k] < grid[0].size() && j+delC[k] >=0 && grid[i+delR[k]][j+delC[k]] && grid[i+delR[k]][j+delC[k]]=='1' && !visited[i+delR[k]][j+delC[k]]){
            dfs(grid, visited, i+delR[k],j+delC[k], delR, delC);
        }
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        vector<int>delR = {1,0,0,-1};
        vector<int>delC = {0,-1,1,0};
        for (int i =0; i< grid.size(); i++){
            for (int j=0; j< grid[0].size(); j++){
                if (!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, visited, i,j, delR, delC);
                    count++;
                }
            }
        }
        return count;
    }
};