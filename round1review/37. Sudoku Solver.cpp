class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve (vector<vector<char>>& board) {
        for(int i = 0; i < 9; i ++) {
            for(int j = 0; j < 9; j ++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c <= '9'; c ++) {
                        if(isvalid(board, i, j, c)) {
                            board[i][j] = c;
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }
    
    bool isvalid(vector<vector<char>>& board, int i, int j, char c) {
        for(int v = 0; v < 9; v ++) {
            if(board[v][j] == c || board[i][v] == c)
                return false;
        }
        for(int v = i / 3 * 3; v < i / 3 * 3 + 3; v ++) {
            for(int w = j / 3 * 3; w < j / 3 * 3 + 3; w ++) {
                if(board[v][w] == c)
                    return false;
            }
        }
        return true;
    }
};