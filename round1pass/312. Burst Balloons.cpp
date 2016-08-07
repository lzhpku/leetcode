public class Solution {
    public int maxCoins(int[] nums) {
        int [] a = new int [nums.length + 2];
        for(int i = 1; i < a.length - 1; i ++)
            a[i] = nums[i - 1];
        a[0] = a[a.length - 1] = 1;
        int [][] dp = new int [a.length][a.length];
        for(int len = 2; len < a.length; len ++) {
            for(int left = 0; left < a.length - len; left ++) {
                int right = left + len;
                for(int d = left + 1; d < right; d ++)
                    dp[left][right] = Math.max(dp[left][right], dp[left][d] + a[left] * a[d] * a[right] + dp[d][right]);
            }
        }
        return dp[0][a.length - 1];
    }
}