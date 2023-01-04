class Solution {
public:
    int countHousePlacements(int n) 
    {
        long long a=1, b=1, ans=0, mod=1e9+7;
        
        for(int i=2;i<=n+1;i++)
        {
            ans=(a+b)%mod;
            
            a=b; b=ans;
        }
        
        return 1L*(ans*ans)%mod;
    }
};