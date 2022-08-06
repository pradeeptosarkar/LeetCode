class Solution {
public:
    
    bool static cmp(vector<int> a, vector<int> b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    
    float calcSlope(int x1, int y1, int x2, int y2)
    {
        return float(y2-y1)/(x2-x1);
    }
    
    int maxPoints(vector<vector<int>>& points) 
    {
        if(points.size()==1 or points.size()==2)
            return points.size();
        
        sort(points.begin(), points.end(), cmp);
        int ans=1;
        vector<unordered_map<float,int>> dp(points.size()+1);
        
        for(int i=1;i<points.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                auto slope=calcSlope(points[j][0],points[j][1],points[i][0],points[i][1]);
                
                if(dp[j].find(slope)!=dp[j].end())
                {
                    dp[i][slope]=1+dp[j][slope];
                    ans=max(ans, dp[i][slope]);
                }
                
                else
                    dp[i][slope]+=1;
            }
        }
        return ++ans;
    }
};