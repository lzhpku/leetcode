class Solution {
public:
    void myswap (vector<vector<int> >& m, int i, int j, int k, int l) {
    m[i][j] ^= m[k][l];
    m[k][l] ^= m[i][j];
    m[i][j] ^= m[k][l];
}

void rotate(vector<vector<int> >& matrix) {
        int size = matrix.size() - 1;
        int s = 0, e = size - 1, j = 0;
        while(s <= e) {
            for(int i = s; i <= e; i ++) {
                int temp = matrix[i][e + 1];
                matrix[i][e + 1] = matrix[j][i];
                matrix[j][i] = temp;
                temp = matrix[e + 1][e + 1 - (i - s)];
                matrix[e + 1][e + 1 - (i - s)] = matrix[j][i];
                matrix[j][i] = temp;
                temp = matrix[e + 1 - (i - s)][j];
                matrix[e + 1 - (i - s)][j] = matrix[j][i];
                matrix[j][i] = temp;
                
                // matrix[j][i] ^= matrix[i][e + 1];
                // matrix[i][e + 1] ^= matrix[j][i];
                // matrix[j][i] ^= matrix[i][e + 1];
                // matrix[j][i] ^= matrix[e + 1][e + 1 - (i - s)];
                // matrix[e + 1][e + 1 - (i - s)] ^= matrix[j][i];
                // matrix[j][i] ^= matrix[e + 1][e + 1 - (i - s)];
                // matrix[j][i] ^= matrix[e + 1 - (i - s)][j];
                // matrix[e + 1 - (i - s)][j] ^= matrix[j][i];
                // matrix[j][i] ^= matrix[e + 1 - (i - s)][j];
                
                // myswap(matrix, j, i, i, e + 1);
                // myswap(matrix, j, i, e + 1, e + 1 - (i - s));
                // myswap(matrix, j, i, e + 1 - (i - s), j);
            }
            j ++;
            s ++;
            e --;
        }
}
};