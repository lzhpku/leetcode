class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minv = 0x7fffffff, ret = 0;
        for(int i = 0; i < prices.size(); i ++) {
            minv = min(minv, prices[i]);
            ret = max(ret, prices[i] - minv);
        }
        return ret;
    }
};