class Solution {
public:
    bool isHappy(int n) {
        int ret = n;
        while(ret >= 10) {
            n = ret;
            ret = 0;
            while(n > 0) {
                ret += (n % 10) * (n % 10);
                n = n / 10;
            }
        }
        return ret == 1 || ret == 7;
    }
};