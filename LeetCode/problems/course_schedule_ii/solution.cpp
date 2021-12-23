class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
    {
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for (auto &v : prerequisites)
        {
            indegree[v[0]]++;
            graph[v[1]].emplace_back(v[0]);
        }
        
        vector<int> res;
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 0)
                res.emplace_back(i);

        for (int i = 0; i < res.size(); ++i)
        {
            int vex = res[i];
            for (int adj : graph[vex])
            {
                indegree[adj]--;
                if (indegree[adj] == 0) res.emplace_back(adj);
            }
        }

        if (res.size() < n) return {}; // if there is cycle(s) in graph
        return res;
    }
};