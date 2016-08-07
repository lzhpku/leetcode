public class Solution {
    public int maximalSquare(char[][] matrix) {
        int ret = 0;
        for(int i = 0; i < matrix.length; i ++) {
            for(int j = 0; j < matrix[0].length; j ++) {
                int a = ((i > 0 && j > 0) ? matrix[i - 1][j - 1] : 0);
                int b = ((i > 0) ? matrix[i - 1][j] : 0);
                int c = ((j > 0) ? matrix[i][j - 1] : 0);
                matrix[i][j] = ((matrix[i][j] == '1') ? (char)(Math.min(a, Math.min(b, c)) + 1) : 0);
                ret = Math.max(ret, matrix[i][j]);
            }
        }
        return ret * ret;
    }
}