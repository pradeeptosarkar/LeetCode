class Solution {
public:
    
    int help(vector<pair<int,int>>& v)
    {
        int n=v.size();
        int ans=0;
        
        vector<int> dp(n,0);
        
        for(int i=0;i<n;i++)
        {
            dp[i]=v[i].second;
            ans=max(ans, dp[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(v[i].second>=v[j].second)
                    dp[i]=max(dp[i], v[i].second+dp[j]);
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        vector<pair<int,int>> v;
        
        for(int i=0;i<scores.size();i++)
            v.push_back({ages[i], scores[i]});
        
        sort(v.begin(), v.end());
        return help(v);
    }
};