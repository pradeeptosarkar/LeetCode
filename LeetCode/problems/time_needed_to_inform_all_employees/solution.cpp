class Solution {
public:
    
    int dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &manager, vector<int> &informTime)
    {
        int ans=0;
        
        for(auto i:adj[node])
            ans=max(ans, dfs(i, adj, manager, informTime));
        
        return ans+informTime[node];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        unordered_map<int, vector<int>> adj;
        
        for(int i=0;i<n;i++)
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        
        return dfs(headID, adj, manager, informTime);                
    }
};