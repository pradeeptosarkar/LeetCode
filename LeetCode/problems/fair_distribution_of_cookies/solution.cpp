class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) 
    {
        int n = cookies.size();
        vector<vector<int>>dp(k + 1, vector<int>((long long)1<<n, INT_MAX));
        
        vector<int>sum((long long)1<<n);
        
        for(int mask=0; mask<(1ll << n); mask++)
        {
            int total=0;
            
            for(int i=0;i<n;i++)
                if(mask & ((long long)1<<i))
                    total+=cookies[i];
                
            sum[mask]=total;
        }

        dp[0][0]=0;
        
        for(int person=1; person<=k; person++)
            for(int mask=0; mask<((long long)1<<n); mask++)
                for(int submask=mask; submask; submask=(submask-1)&mask)
                    dp[person][mask] = min(dp[person][mask], max(sum[submask], dp[person - 1][mask^submask]));

        return dp[k][((long long)1<<n)-1];
    }   
};