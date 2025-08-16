class Solution {
public:
    bool isvalid(int row, int col, int n, int m){
        if (row>=0 && row<n && col>=0 && col<m) return true;
        return false;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans = isWater, visited(n, (vector<int>(m, 0)));
        queue<pair<pair<int,int>, int>> q; // Stored as { {row,col}, steps};
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (isWater[i][j] == 1){
                    ans[i][j] = 0;
                    visited[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, 1, 0, -1};
        while (!q.empty()){
            auto [row,col] = q.front().first ;
            int steps = q.front().second; q.pop();
            for (int i=0; i<4; i++){
                int newr = row+dx[i], newc = col+dy[i];
                if (isvalid(newr, newc, n,m) && !isWater[newr][newc] && !visited[newr][newc]){
                    ans[newr][newc] = steps+1; visited[newr][newc]=1;
                    q.push({{newr, newc}, steps+1}); 
                }
            }
        }
        return ans;
    }
};