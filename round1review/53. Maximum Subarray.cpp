class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0], temp = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            temp = max(nums[i], nums[i] + temp);
            ret = max(temp, ret);
        }
        return ret;
    }
};