//考虑三个问题：
//1.什么时候更新len
//2.什么时候跳出循环，达到目标位置就可以，这时候要检查时候需要跳最后一步
//3.更新计数器，当前到达前一个len的时候更新
//

class Solution {
public:
    int jump(vector<int>& nums) {
        int len = 0, ret = 0, pre = 0;
        for(int i = 0; i <= len; i ++) {
            if(nums[i] + i > len)
                len = nums[i] + i;
            if(len >= nums.size() - 1)
                return pre < nums.size() - 1 ? ++ ret : ret;
            if(i == pre) {
                ret ++;
                pre = len;
            }
        }
        return ret;
    }
};