public class Solution {
    public int maxProfit(int[] prices) {
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE, re1 = 0, re2 = 0;
        for(int i = 0; i < prices.length; i ++) {
            re2 = Math.max(re2, hold2 + prices[i]);
            hold2 = Math.max(hold2, re1 - prices[i]);
            re1 = Math.max(re1, hold1 + prices[i]);
            hold1 = Math.max(hold1, -prices[i]);
        }
        return re2;
    }
}