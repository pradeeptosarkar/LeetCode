class Solution {
public:
    int longestCycle(vector<int>& edges) 
    {
        int ans=-1;
        vector<pair<int,int>> visited(edges.size());
        
        for(int i=0;i<edges.size();i++)
        {
            int len=1, curr=i;
            
            while(curr!=-1 and visited[curr].second==0)
            {
                visited[curr]=make_pair(i,len++);
                curr=edges[curr];
            }
            
            if(curr!=-1 and visited[curr].first==i)
                ans=max(ans, len-visited[curr].second);
        }
        return ans;        
    }
};