class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        queue<pair<pair<int,int>, int>>pos_rotten; int count_non_zero=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 2){
                    pos_rotten.push({{i,j},0});
                }
                if (grid[i][j] != 0){
                    count_non_zero++;
                }
            }
        }
        if (count_non_zero == 0) return 0;
        // for (auto [v,f]:pos_rotten) cout<<"x="<<v<<",y="<<f<<endl;
        vector<pair<int,int>>dx_dy = {{-1,0},{0,1},{1,0},{0,-1}};
        int max_time = -1;
        while (!pos_rotten.empty()){
            int r=pos_rotten.front().first.first;
            int c=pos_rotten.front().first.second;
            int t=pos_rotten.front().second;
            pos_rotten.pop();
            max_time = max(max_time, t);
            for (int i=0; i<4; i++){
                int new_r  = r+dx_dy[i].first;
                int new_c  = c+dx_dy[i].second;
                if ((new_r <n && new_r>=0) && (new_c <m && new_c>=0) && visited[new_r][new_c] != 1 && grid[new_r][new_c]==1 ){
                    pos_rotten.push({{new_r,new_c}, t+1});
                    visited[new_r][new_c] = 1;
                    grid[new_r][new_c]=2;
                }
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]==1 && grid[i][j]!=2) return -1;
            }
        }
        return max_time;
    }
};