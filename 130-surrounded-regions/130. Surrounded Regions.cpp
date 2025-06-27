class Solution {
public:
    void dfs(vector<vector<char>>&b, int i, int j,vector<vector<int>>&visited,vector<vector<bool>>&pos,  vector<pair<int,int>>&d ){
        visited[i][j]=1;
        pos[i][j]=true;
        for (auto [dx,dy]:d){
            int newx = i+dx, newy = j+dy;
            if ((newx>=0 && newx<b.size())&& (newy>=0 && newy<b[0].size()) && b[newx][newy]=='O' && !visited[newx][newy]){
                // cout<<"marked x="<<newx<<", newy="<<newy<<endl;
                dfs(b,newx,newy,visited, pos, d);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n= board.size(), m= board[0].size();
        vector<pair<int,int>>d = {{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>>possible(n,vector<bool>(m,0));
        for (int j=0; j<m; j++) {
            vector<vector<int>>vis(n,vector<int>(m,0));
            if (board[0][j]=='O') {
                // cout<<"Yoho entering 1";
                dfs(board, 0, j, vis, possible, d);
            }
        }
        for (int j=0; j<m; j++) {
            vector<vector<int>>vis(n,vector<int>(m,0));
            if (board[n-1][j]=='O') {
                // cout<<"Yoho entering 2";
                dfs(board, n-1, j, vis, possible, d);
            }
        }
        for (int i=0; i<n; i++) {
            vector<vector<int>>vis(n,vector<int>(m,0));
            if (board[i][0]=='O') {
                // cout<<"Yoho entering 3";
                dfs(board, i, 0, vis, possible, d);
            }
        }
        for (int i=0; i<n; i++) {
            vector<vector<int>>vis(n,vector<int>(m,0));
            if (board[i][m-1]=='O') {
                // cout<<"Yoho entering 4";
                dfs(board, i, m-1, vis, possible, d);
            }
        }
        // for (int i=0; i<n; i++){
        //     cout<<"now printing row i="<<i<<";";
        //     for (auto j:possible[i]) cout<<j<<","; cout<<endl;
        // }
        for (int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (board[i][j]=='O' && !possible[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};