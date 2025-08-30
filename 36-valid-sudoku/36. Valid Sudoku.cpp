class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // NO need to solve this, ONLY Validate.
        // Validate rows
        for (int i=0; i<9; i++){
            vector<int>freq(10,0);
            for (int j=0; j<9; j++){
                if (board[i][j] != '.') {
                    freq[board[i][j]-'0']++;
                    if (freq[board[i][j]-'0'] > 1) return false;
                }
            }
        }
        // Validate Columns
        for (int i=0; i<9; i++){
            vector<int>freq(10,0);
            for (int j=0; j<9; j++){
                if (board[j][i] != '.') {
                    freq[board[j][i]-'0']++;
                    if (freq[board[j][i]-'0'] > 1) return false;
                }
            }
        }
        // Validate grids;
        for (int grid_counter=1; grid_counter<10; grid_counter++){
            vector<int>freq(10,0);
            if (grid_counter<=3){
                for (int i=0; i<3; i++){
                    for (int j = 0+(grid_counter-1)*3; j<=2+(grid_counter-1)*3; j++){
                        if (board[i][j] != '.') {
                            freq[board[i][j]-'0']++;
                            if (freq[board[i][j]-'0'] > 1) return false;
                        }
                    }
                }
            }else if (grid_counter<=6){
                for (int i=3; i<6; i++){
                    for (int j = 0+(grid_counter-4)*3; j<=2+(grid_counter-4)*3; j++){
                        if (board[i][j] != '.') {
                            freq[board[i][j]-'0']++;
                            if (freq[board[i][j]-'0'] > 1) return false;
                        }       
                    }
                }
            }else{
                for (int i=6; i<9; i++){
                    for (int j = 0+(grid_counter-7)*3; j<=2+(grid_counter-7)*3; j++){
                        if (board[i][j] != '.') {
                            freq[board[i][j]-'0']++;
                            if (freq[board[i][j]-'0'] > 1) return false;
                        }       
                    }
                }
            }
        }
        return true;
    }
};