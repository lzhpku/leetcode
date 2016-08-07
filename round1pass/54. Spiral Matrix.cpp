public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> ret = new ArrayList<Integer> ();
        if(matrix.length == 0)
            return ret;
        int xs = 0, xe = matrix.length - 1;
        int ys = 0, ye = matrix[0].length - 1;
        while(xs <= xe && ys <= ye) {
            for(int i = ys; i <= ye; i ++)
                ret.add(matrix[xs][i]);
            xs ++;
            for(int i = xs; i <= xe; i ++)
                ret.add(matrix[i][ye]);
            ye --;
            if(xs <= xe)
                for(int i = ye; i >= ys; i --)
                    ret.add(matrix[xe][i]);
            xe --;
            if(ys <= ye)
                for(int i = xe; i >= xs; i --)
                    ret.add(matrix[i][ys]);
            ys ++;
        }
        return ret;
    }
}