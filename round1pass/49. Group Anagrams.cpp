class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, multiset<string>> m;
        for(int i = 0; i < strs.size(); i ++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].insert(strs[i]);
        }
        vector<vector<string>> ret;
        for(auto item : m) {
            vector<string> temp(item.second.begin(), item.second.end());
            ret.push_back(temp);
        }
        return ret;
    }
};