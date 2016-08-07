class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        return max(rob1(nums, 0, nums.size() - 1), rob1(nums, 1, nums.size()));
    }
    int rob1(vector<int>& nums, int start, int end) {
        int byesterday = 0, yesterday = 0, today = 0;
        for(int i = start; i < end; i ++) {
            today = max(byesterday + nums[i], yesterday);
            byesterday = yesterday;
            yesterday = today;
        }
        return today;
    }
};