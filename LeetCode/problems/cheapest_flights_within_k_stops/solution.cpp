class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>> graph(n);
        
        for(auto i:flights)
            graph[i[0]].push_back({i[1],i[2]});
        
        vector<int> dist(n, INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        int stops=0;
        
        while(stops<=k and !q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto [node, dis]=q.front();
                q.pop();
                
                for(auto [neighbor, price] : graph[node])
                {
                    if(price+dis>=dist[neighbor])
                        continue;
                    
                    dist[neighbor]=price+dis;
                    q.push({neighbor, dist[neighbor]});
                }
            }
            
            stops++;
        }
        
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};