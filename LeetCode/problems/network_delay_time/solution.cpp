class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        vector<vector<int>>adj[n+1];
        
        for(int i=0;i<times.size();i++)
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        
        while(!pq.empty())
        {
            int distance=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            
            for(auto i: adj[prev])
            {
                int next=i[0];
                int nextDist=i[1];
                if(dist[next]>(dist[prev]+nextDist))
                {
                    dist[next]=dist[prev]+nextDist;
                    pq.push({dist[next],next});
                }
            }
        }
        
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            
            sum=max(sum,dist[i]);
        }
        return sum;
    }
};