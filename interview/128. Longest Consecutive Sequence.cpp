class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> hash;
        int ret = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if(hash.find(nums[i]) != hash.end())
                continue;
            int left = 0, right = 0;
            if(hash.find(nums[i] - 1) != hash.end())
                left = hash[nums[i] - 1];
            if(hash.find(nums[i] + 1) != hash.end())
                right = hash[nums[i] + 1];
            int temp = left + right + 1;
            ret = max(ret, temp);
            hash[nums[i] - left] = temp;
            hash[nums[i] + right] = temp;
            hash[nums[i]] = temp;
        }
        return ret;
    }
};