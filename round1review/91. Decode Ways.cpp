class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        vector<int> ret (n + 1, 0);
        ret[n] = 1;
        ret[n - 1] = (s[n - 1] == '0' ? 0 : 1);
        for(int i = n - 2; i >= 0; i --) {
            if(s[i] == '0')
                continue;
            else
                ret[i] = (s.substr(i, 2) <= "26" ? ret[i + 1] + ret[i + 2] : ret[i + 1]);
        }
        return ret[0];
    }
};