public class Solution {
    public char [][] map;
    public boolean flagCol [];
    public boolean flagLeft [];
    public boolean flagRight [];
    public List<List<String>> ret = new ArrayList<List<String>>();
    
    public List<List<String>> solveNQueens(int n) {
        flagCol = new boolean [n];
        flagLeft = new boolean [2 * n - 1];
        flagRight = new boolean [2 * n - 1];
        for(int i = 0; i < n; i ++)
            flagCol[i] = true;
        for(int i = 0; i < 2 * n - 1; i ++)
            flagLeft[i] = flagRight[i] = true;
        map = new char [n][n];
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                map[i][j] = '.';
        dfs(0, n);
        return ret;
    }
    
    public void dfs (int level, int n) {
        if(level == n) {
            List<String> temp = new ArrayList<>();
            for(int i = 0; i < n; i ++)
                temp.add(String.valueOf(map[i]));
            ret.add(temp);
            return;
        }
        for(int i = 0; i < n; i ++) {
            if(flagCol[i] && flagLeft[level + i] && flagRight[level + n - 1 - i]) {
                flagCol[i] = flagLeft[level + i] = flagRight[level + n - 1 - i] = false;
                map[level][i] = 'Q';
                dfs(level + 1, n);
                map[level][i] = '.';
                flagCol[i] = flagLeft[level + i] = flagRight[level + n - 1 - i] = true;
            }
        }
    }
}