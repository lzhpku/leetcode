class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0, cool = 0, hold = -0x7fffffff;
        for(int i = 0; i < prices.size(); i ++) {
            int presold = sold;
            sold = hold + prices[i];
            hold = max(hold, cool - prices[i]);
            cool = max(presold, cool);
        }
        return max(cool, sold);
    }
};