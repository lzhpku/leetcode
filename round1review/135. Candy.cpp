﻿class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n < 1)
            return 0;
        vector<int> ret(n, 1);
        for(int i = 0; i < n - 1; i ++) {
            if(ratings[i] < ratings[i + 1])
                ret[i + 1] = ret[i] + 1;
        }
        for(int i = n - 1; i > 0; i --) {
            if(ratings[i] < ratings[i - 1])
                ret[i - 1] = max(ret[i - 1], ret[i] + 1);
        }
        int sum = 0;
        for(int i = 0; i < n; i ++)
            sum += ret[i];
        return sum;
    }
};