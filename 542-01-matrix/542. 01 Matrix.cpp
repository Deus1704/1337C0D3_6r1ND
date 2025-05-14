class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(); int m=mat[0].size();
        vector<vector<int>>ans(n, vector<int>(m,0));
        vector<vector<int>>visited(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while (!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            for (int i=0; i<4; i++){
                int new_row = row+dx[i];
                int new_col = col+dy[i];
                if ( (new_row<n && new_row>=0) &&(new_col<m && new_col>=0) && !visited[new_row][new_col] && mat[new_row][new_col]==1 ){
                    visited[new_row][new_col]=1;
                    ans[new_row][new_col]=step+1;
                    q.push({{new_row,new_col}, step+1});
                }
            }
        }
        return ans;
    }
};