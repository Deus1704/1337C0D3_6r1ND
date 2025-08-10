class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>ans = grid; int ptr = x+k;
        for (int i=x; i<x+k; i++){
            for (int j=y; j<y+k; j++){
                ans[i][j] = grid[ptr-1][j];
            }ptr--;
        }
        return ans;
    }
};