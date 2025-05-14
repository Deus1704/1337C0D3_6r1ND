class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();int m=image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        vector<pair<int,int>>dxy = {{-1,0},{0,1},{1,0},{0,-1}};
        queue<pair<int,int>>q; int original_color = image[sr][sc]; 
        q.push({sr,sc});image[sr][sc]=color;
        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i=0; i<4; i++){
                int new_row = row+dxy[i].first;
                int new_col = col+dxy[i].second;
                if ( (new_row>=0 && new_row<n) && (new_col>=0 && new_col<m) && visited[new_row][new_col]==-1 && image[new_row][new_col] == original_color  ){
                    q.push({new_row,new_col});
                    visited[new_row][new_col] = 1;
                    image[new_row][new_col] = color;
                }
            }
        }
        return image;
    }
};