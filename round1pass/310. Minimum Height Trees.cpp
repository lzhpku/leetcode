class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        if(n == 1) {
            ret.push_back(0);
            return ret;
        }
        
        vector<set<int>> hash;
        set<int> t;
        for(int i = 0; i < n; i ++)
            hash.push_back(t);
        for(int i = 0; i < edges.size(); i ++) {
            hash[edges[i].first].insert(edges[i].second);
            hash[edges[i].second].insert(edges[i].first);
        }
        
        for(int i = 0; i < n; i ++) {
            if(hash[i].size() == 1)
                ret.push_back(i);
        }
        while(n > 2) {
            int size = ret.size();
            for(int i = 0; i < size; i ++) {
                int from = ret[0];
                int to = *(hash[from].begin());
                hash[from].erase(to);
                hash[to].erase(from);
                if(hash[to].size() == 1)
                    ret.push_back(to);
                ret.erase(ret.begin());
            }
            n = n - size;
        }
        return ret;
    }
};