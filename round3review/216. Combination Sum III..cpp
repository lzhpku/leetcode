class Solution {
public:
    vector<vector<int>> ret;
    vector<int> temp;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ret;
    }
    
    void dfs(int start, int k, int n) {
        if(k == 0 && n == 0) {
            ret.push_back(temp);
            return;
        }
        if(k == 0 || n == 0)
            return;
        for(int i = start; i <= 10 - k && i <= n; i ++) {
            temp.push_back(i);
            dfs(i + 1, k - 1, n - i);
            temp.pop_back();
        }
    }
};