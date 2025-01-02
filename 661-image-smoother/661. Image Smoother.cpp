class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans = img;
        int n = img.size(), m= img[0].size();
        vector<int> dx = {0,0,1,1,1,0,-1,-1,-1};
        vector<int> dy = {0,-1,-1,0,1,1,1,0,-1};
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int count = 0;int summ = 0;
                for (int k=0; k<dx.size(); k++){
                    int new_x = i+dx[k], new_y = j+dy[k];
                    if ((new_x<n && new_x>=0) && (new_y<m && new_y>=0)){
                        summ+= img[new_x][new_y];
                        count++;
                    }
                }
                // cout<<"@ i,j="<<i<<","<<j<<"The Count registerd= "<<count<<" & sum="<<summ<<endl;
                ans[i][j] = summ/count;
            }
        }
        return ans;
    }
};