class Solution {
public:
    int mod=1000000007;
    int solver(string &s,int k,int i,int n,vector<int>&dp)
    {
        
        if(i==n)
          return 1;
        
        if(s[i]=='0')
          return 0; 
        
        if(dp[i]!=-1)
            return dp[i];
        
        long int nums=0,ans=0;
        for(int j=i;(nums*10+(s[j]-'0'))<=k && j<n;j++)
        {
            nums=nums*10+(s[j]-'0');
            ans=(ans+solver(s,k,j+1,n,dp))%mod;
        }
        return dp[i]=ans%mod;
    }
    int numberOfArrays(string s, int k) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return solver(s,k,0,n,dp);
    }
};