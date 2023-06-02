class Solution {
public:
    int dfs(int node, unordered_map<int, vector<int> > &mp, vector<bool> &vis)
    {
        if(vis[node]){
           return 0;
        }
        vis[node]=true;
        int num=1;
        for(auto it: mp[node])
        {
            num +=dfs(it,mp,vis);
        }
        return num;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int> > mp;
        int n=bombs.size();
        for(int i=0;i<n;i++)
        {
            long long  x1,y1,r1;
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                     long long x2,y2,r2;
                     x2=abs(x1-bombs[j][0]);
                     y2=abs(y1-bombs[j][1]);
                    if(x2*x2+y2*y2<=r1*r1)
                    {
                        mp[i].push_back(j);
                    }
                }
            }
        }
       
        int maxi=-1;
        for(int i=0;i<bombs.size();i++)
        {
            vector<bool> vis(bombs.size(),false);
          maxi=max(maxi,dfs(i,mp,vis));
        }
        return maxi;
    }
};