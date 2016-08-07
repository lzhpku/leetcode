class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int i = 0;
        while(i < nums.size()) {
            ret.push_back(to_string(nums[i]));
            int j = i + 1;
            while(j < nums.size() && nums[j] == nums[j - 1] + 1)
                j ++;
            if(j > i + 1)
                ret.back() += "->" + to_string(nums[j - 1]);
            i = j;
        }
        return ret;
    }
};