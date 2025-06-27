class Solution {
private:
    bool isValid(int row, int col, vector<string>& board){
        int r = row, c = col;

        // Check upper left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        r = row;
        c = col;

        // Check upper
        while (r >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
        }

        r = row;
        c = col;

        // Check upper right diagonal
        while (r >= 0 && c < board.size()) {
            if (board[r][c] == 'Q') return false;
            r--;
            c++;
        }

        // If no queens are found, it's safe
        return true;
    }

    void func(int row,  vector<vector<string>>& ans, vector<string>& board){
        if(row == board.size()){
            ans.push_back(board);
            return;
        }

        for(int col=0; col<board.size(); col++){
            if(isValid(row, col, board)){
                board[row][col] = 'Q';
                func(row+1, ans, board);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        func(0, ans, board);
        return ans;
    }
};