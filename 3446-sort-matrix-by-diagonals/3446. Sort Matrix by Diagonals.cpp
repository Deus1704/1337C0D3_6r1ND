class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // vector<vector<int>>top_right, bottom_right;
        // top right;
        for (int i=1; i<=n-2; i++){
            vector<int>temp;
            int start = i, base=0;
            while (start <= n-1){
                temp.push_back(grid[base][start]); base++; start++;
            }
            sort(temp.begin(), temp.end());
            // for(auto &k:temp) cout<<k<<","; cout<<endl;
            int updatey = i, updatex=0;
            while (updatey <= n-1){
                grid[updatex][updatey] = temp[updatex];
                updatex++; updatey++;
            }
        }
        // Main Diagonal;
        vector<int>temp;
        int start = 0;
        while (start <= n-1){
            temp.push_back(grid[start][start]); start++;
        }
        sort(temp.rbegin(), temp.rend());
        // for(auto &k:temp) cout<<k<<","; cout<<endl;
        int updatey = 0;
        while (updatey <= n-1){
            grid[updatey][updatey] = temp[updatey];
            updatey++;
        }
        // Bottom Left;
        for (int i=1; i<=n-2; i++){
            vector<int>temp;
            int start = i, base=0;
            while (start <= n-1){
                temp.push_back(grid[start][base]); base++; start++;
            }
            sort(temp.rbegin(), temp.rend());
            // for(auto &k:temp) cout<<k<<","; cout<<endl;
            int updatey = i, updatex=0;
            while (updatey <= n-1){
                grid[updatey][updatex] = temp[updatex];
                updatex++; updatey++;
            }
        }
        return grid;
    }
};