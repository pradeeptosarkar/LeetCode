class Solution {
public:
    
    void dfs(int node, int n, vector<vector<int>>& isConnected, vector<bool>& vis)
    {
        vis[node]=true;
        
        for(int i=0;i<n;i++)
        {
            if(isConnected[node][i] and !vis[i])
                dfs(i, n, isConnected, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n=isConnected.size();
        int ans=0;
        vector<bool> vis(n);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i, n, isConnected, vis);
            }
        }
        
        return ans;
    }
};