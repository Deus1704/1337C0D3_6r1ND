class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>zeroloc;
        for (int i =0; i<matrix.size(); i++){
            for (int j =0; j<matrix[0].size(); j++){
                if (!matrix[i][j]){
                    zeroloc.push_back({i,j});
                }
            }
        }
        for (auto pai : zeroloc){
            for (int k=0; k<matrix.size(); k++){
                matrix[k][pai.second] = 0;
            }
            for (int k=0; k<matrix[0].size(); k++){
                matrix[pai.first][k] = 0;
            }
        }
    }
};