class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> indegree(n+1,0), outdegree(n+1,0);
        
        for(auto i:trust)
        {
            outdegree[i[0]]++;
            indegree[i[1]]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(indegree[i]==n-1 and outdegree[i]==0)
                return i;
        }
        
        return -1;
    }
};