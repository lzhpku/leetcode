class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ret = nums.size() + 1, l = 0, r = 0, size = nums.size();
        int curSum = 0;
        while(r < size) {
            curSum += nums[r ++];
            while(curSum >= s) {
                ret = min(ret, r - l);
                curSum -= nums[l ++];
            }
        }
        return ret <= nums.size() ? ret : 0;
    }
};