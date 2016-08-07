class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0), index(n, 0);
        for(int i = 0; i < n; i ++)
            index[i] = i;
        partition(nums, count, index, 0, n - 1);
        return count;
    }
    
    void partition(vector<int>& nums, vector<int>& count, vector<int>& index, int s, int e) {
        if(s >= e)
            return;
        int m = (s + e) / 2;
        partition(nums, count, index, s, m);
        partition(nums, count, index, m + 1, e);
        merge(nums, count, index, s, m, e);
    }
    
    void merge(vector<int>& nums, vector<int>& count, vector<int>& index, int s, int m, int e) {
        vector<int> temp(e - s + 1, 0);
        int i = s, j = m + 1, t = 0, rever = 0;
        while(i <= m && j <= e) {
            if(nums[index[i]] <= nums[index[j]]) {
                count[index[i]] += rever;
                temp[t ++] = index[i ++];
            }
            else {
                rever ++;
                temp[t ++] = index[j ++];
            }
        }
        while(i <= m) {
            count[index[i]] += rever;
            temp[t ++] = index[i ++];
        }
        while(j <= e)
            temp[t ++] = index[j ++];
        // for(int i = 0; i < temp.size(); i ++)
        //     index[i + s] = temp[i];
        copy(temp.begin(), temp.end(), index.begin() + s);
    }
};