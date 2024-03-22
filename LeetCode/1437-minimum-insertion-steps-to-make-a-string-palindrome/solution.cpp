class Solution {
public:
    int minInsertions(string s) 
    {
        int n=s.length();
        string r=s;
        reverse(r.begin(), r.end());
        
        //vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==r[j-1])
                    curr[j] = 1+prev[j-1];
                
                else
                    curr[j] = max(curr[j-1], prev[j]);
            }
            
            prev=curr;
        }
        
        return n-curr[n];
    }
};
