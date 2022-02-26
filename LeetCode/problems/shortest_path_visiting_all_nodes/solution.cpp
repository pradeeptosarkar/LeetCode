//::Pradeepto Sarkar LC847:://

class Solution{
public:
    int shortestPathLength(vector<vector<int>>& graph){
        
        int len[12][12];
        int n=graph.size();
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<n;++j) len[i][j]=n;
            len[i][i]=0;
            for (int j=0;j<graph[i].size();++j) len[i][graph[i][j]]=1;
        }
        
        for (int k=0;k<n;++k)
            for (int i=0;i<n;++i)
                for (int j=0;j<n;++j)
                    if (i!=k&&j!=k&&i!=j&&len[i][j]>len[i][k]+len[k][j]) len[i][j]=len[i][k]+len[k][j];
        
        int dp[1<<12][12];
        for (int i=0;i<1<<n;++i)
        	for (int j=0;j<n;++j) 
                dp[i][j]=n*n;
        
        for (int i=0;i<n;++i) 
            dp[1<<i][i]=0;
        
        for (int i=1;i<(1<<n);++i)
        {
            for (int j=0;j<n;++j)
                if ((i>>j)&1)
                    for (int k=0;k<n;++k)
                        if (j!=k&&(i>>k)&1)
                            dp[i][j]=min(dp[i][j],dp[i&((1<<n)-1-(1<<j))][k]+len[k][j]);
        }
        int minlen=INT_MAX;
        for (int i=0;i<n;++i) minlen=min(minlen,dp[(1<<n)-1][i]);
        return minlen;
    }
};