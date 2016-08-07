public class Solution {
    public boolean flagCol [];
    public boolean flagLeft [];
    public boolean flagRight [];
    public int ret = 0;
    
    public int totalNQueens(int n) {
        flagCol = new boolean [n];
        flagLeft = new boolean [2 * n - 1];
        flagRight = new boolean [2 * n - 1];
        for(int i = 0; i < n; i ++)
            flagCol[i] = true;
        for(int i = 0; i < 2 * n - 1; i ++)
            flagLeft[i] = flagRight[i] = true;
        dfs(0, n);
        return ret;
    }
    
    public void dfs (int level, int n) {
        if(level == n) {
            ret ++;
            return;
        }
        for(int i = 0; i < n; i ++) {
            if(flagCol[i] && flagLeft[level + i] && flagRight[level + n - 1 - i]) {
                flagCol[i] = flagLeft[level + i] = flagRight[level + n - 1 - i] = false;
                dfs(level + 1, n);
                flagCol[i] = flagLeft[level + i] = flagRight[level + n - 1 - i] = true;
            }
        }
    }
}