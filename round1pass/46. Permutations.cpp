class Solution {
public:
    vector<vector<int>> ret;
    vector<int> temp;
    vector<bool> flag;
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i ++)
            flag.push_back(false);
        dfs(nums, n, 0);
        return ret;
    }
    
    void dfs(vector<int>& nums, int n, int count) {
        if(count == n) {
            ret.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i ++) {
            if(!flag[i]) {
                temp.push_back(nums[i]);
                flag[i] = true;
                dfs(nums, n, count + 1);
                flag[i] = false;
                temp.pop_back();
            }
        }
    }
};