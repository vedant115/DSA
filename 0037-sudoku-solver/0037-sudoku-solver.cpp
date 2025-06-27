class Solution {
private:
    bool rulesMet(vector<vector<char>>& board, int row, int col, char digit){
        int startRow = (row/3)*3, startCol = (col/3)*3;
        for(int i=0; i<9; i++){
            if(board[row][i] == digit) return false;
            if(board[i][col] == digit) return false;
            if(board[startRow + i/3][startCol + i%3] == digit) return false;
        }
        return true;
    }

    bool func(vector<vector<char>>& board){
        int n = 9;  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {  
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (rulesMet(board, i, j, digit)) {  
                            board[i][j] = digit;  

                            if (func(board)) return true;

                            board[i][j] = '.';  
                        }
                    }
                    return false;  
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char> >& board) {
        func(board);
    }
};