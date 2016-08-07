class Solution {
public:
    void check(vector<vector<char> >& board, int x, int y) {
        if(board[x][y] == 'O') {
            board[x][y] = '1';
            if(x > 1)
                check(board, x - 1, y);
            if(y > 1)
                check(board, x, y - 1);
            if(x < board.size() - 1)
                check(board, x + 1, y);
            if(y < board[0].size() - 1)
                check(board, x, y + 1);
        }
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0)
            return;
        int col = board[0].size();
        for(int i = 0; i < row; i ++) {
            check(board, i, 0);
            if(col > 1)
                check(board, i, col - 1);
        }
        for(int i = 0; i < col; i ++) {
            check(board, 0, i);
            if(row > 1)
                check(board, row - 1, i);
        }
        for(int i = 0; i < row; i ++)
            for(int j = 0; j < col; j ++)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
        for(int i = 0; i < row; i ++)
            for(int j = 0; j < col; j ++)
                if(board[i][j] == '1')
                    board[i][j] = 'O';
        return;
    }
};