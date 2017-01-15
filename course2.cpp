class Solution {
// queue version of topological sort
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
        {
            indegree[p.first]++;
            if (adj[p.second].size() == 0) {
                vector<int> tmp{p.first};
                adj[p.second] = tmp;
            } else {
                adj[p.second].emplace_back(p.first);
            }
        }
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.emplace(i);
                res.emplace_back(i);
            }
        }
        while (res.size() < numCourses) {
            if (q.empty()) return {};
            int u = q.front();
            q.pop();
            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i];
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.emplace(v);
                    res.emplace_back(v);
                }
            }
        }
        return res;
    }
};
