class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // check the size
        if (board.empty() || board[0].empty()) {
            return false;
        }

        // get dimensions
        int rows = board.size();
        int cols = board[0].size();

        // DFS definition
        function<bool(int, int, int)> DFS = [&](int i, int j, int k) {
            if (k == word.length())
                return true;

            if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[k])
                return false;

            char temp = board[i][j];
            board[i][j] = '\0';

            if (DFS(i + 1, j, k + 1) || DFS(i - 1, j, k + 1) || 
                DFS(i, j + 1, k + 1) || DFS(i, j - 1, k + 1))
                return true;

            board[i][j] = temp;
            return false;
        };

        // loop over cells and perform DFS
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && DFS(i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
