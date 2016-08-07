public class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int l = Math.max(A, E);
        int r = Math.min(C, G);
        int b = Math.max(B, F);
        int t = Math.min(D, H);
        int overlap = 0;
        if(l < r && b < t)
            overlap = (r - l) * (t - b);
        return (C - A) * (D - B) + (G - E) * (H - F) - overlap;
    }
}