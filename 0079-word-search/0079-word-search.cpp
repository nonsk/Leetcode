class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int indexi,
               int indexj) {
        if (indexi < 0 || indexi >= board.size() || indexj < 0 ||
            indexj >= board[0].size()) {
            return false;
        }
        if (board[indexi][indexj] != word[0]) {

            return false;
        }
        if (word.size() == 1) {
            return true;
        }
        string yo = word.substr(1, word.size());
        char temp = board[indexi][indexj];
        board[indexi][indexj] = '#';
        bool found = solve(board, word.substr(1), indexi + 1, indexj) ||
                     solve(board, word.substr(1), indexi - 1, indexj) ||
                     solve(board, word.substr(1), indexi, indexj + 1) ||
                     solve(board, word.substr(1), indexi, indexj - 1);

        board[indexi][indexj] = temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // return solve(board, word, 0, 0);
        bool flag = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    flag = flag || solve(board, word, i, j);
                }
            }
        }
        return flag;
    }
};