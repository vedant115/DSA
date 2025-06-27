class Solution {
private:
    bool func(int ind, int i, int j, vector<vector<char>>& board, string word){
        if(ind == word.size()-1 && board[i][j] == word[ind])
            return true;
        if(board[i][j] == ' ' || board[i][j] != word[ind])
            return false;

        char x = board[i][j];
        board[i][j] = ' ';

        bool ans = false;
        if(i-1>=0) ans |= func(ind+1, i-1, j, board, word);
        if(i+1<board.size()) ans |= func(ind+1, i+1, j, board, word);
        if(j-1>=0) ans |= func(ind+1, i, j-1, board, word);
        if(j+1<board[0].size()) ans |= func(ind+1, i, j+1, board, word);

        board[i][j] = x;

        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (func(0, i, j, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};