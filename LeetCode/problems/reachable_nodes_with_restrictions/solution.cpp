class Solution {
public:
    
    void dfs(int curr, vector<vector<int>> &graph, vector<bool> &visited, set<int> &banned, int &ans)
    {
        if(visited[curr])
            return;
        
        visited[curr]=1;
        
        ans++;
        
        for(auto i:graph[curr])
            if(banned.find(i)==banned.end())
                dfs(i, graph, visited, banned, ans);
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) 
    {
        vector<vector<int>> graph(n);
        vector<bool> visited(n,0);
        set<int> banned(restricted.begin(), restricted.end());
        int ans=0;
        
        for(auto i:edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        dfs(0, graph, visited, banned, ans);
        return ans;
    }
};