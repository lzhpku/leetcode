class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> temp(numCourses, false);
        vector<vector<bool>> matrix(numCourses, temp);
        vector<int> indegree(numCourses, 0);
        for(pair<int, int> p : prerequisites) {
            int from = p.first;
            int to = p.second;
            if(!matrix[from][to])
                indegree[to] ++;
            matrix[from][to] = true;
        }
        int count = 0;
        queue<int> q;
        for(int i = 0; i < numCourses; i ++)
            if(indegree[i] == 0)
                q.push(i);
        vector<int> ret;
        while(!q.empty()) {
            int course = q.front();
            ret.push_back(course);
            q.pop();
            count ++;
            for(int i = 0; i < numCourses; i ++) {
                if(matrix[course][i]) {
                    indegree[i] --;
                    if(indegree[i] == 0)
                        q.push(i);
                }
            }
        }
        reverse(ret.begin(), ret.end());
        if(count != numCourses)
            ret.clear();
        return ret;
    }
};