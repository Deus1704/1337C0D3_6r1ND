class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char d){
        for(int i=0; i<9; i++){
            if (board[row][i] == d) return false;
            if (board[i][col] == d) return false; 
        }
        // check the smaller square grids
        int start_row = (row/3)*3, start_col = (col/3)*3;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (board[start_row+i][start_col+j] == d) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] == '.'){
                    for(char k = '1'; k<='9'; k++){
                        if (isValid(board, i, j, k)){
                            board[i][j] = k;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool fake = solve(board);
    }
};