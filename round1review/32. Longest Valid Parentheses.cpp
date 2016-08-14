class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> v;
        int ret = 0;
        for(int i = 0; i < s.size(); i ++) {
            if(!v.empty()) {
                if(s[v.back()] == '(' && s[i] == ')') {
                    v.pop_back();
                    ret = max(ret, (v.empty() ? i - (-1) : i - v.back()));
                }
                else
                    v.push_back(i);
            }
            else
                v.push_back(i);
        }
        return ret;
    }
};