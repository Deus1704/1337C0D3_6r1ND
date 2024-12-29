class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ops = 0;
        int n=grid.size(),m=grid[0].size();
        for (int i=0; i<n-1; i++){
            for (int j=0; j<m; j++){
                int temp = grid[i+1][j] - grid[i][j] ;
                // cout<<"The i="<<i<<" and j="<<j<<" & The temp ="<<temp<<" and ops="<<ops<<endl; 
                if (temp <= 0){
                    ops+= abs(temp)+1;
                    grid[i+1][j] += abs(temp)+1;
                }
            }
        }
        return ops;
    }
};