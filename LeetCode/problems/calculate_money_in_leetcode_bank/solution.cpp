class Solution {
public:
    int totalMoney(int n) 
    {
        int a=n/7;
        int b=n%7;
        
        int ans;
        if(a>=1)
        ans=(a*(49+(7*a)))/2;
        
        if(b==0)
            return ans;
        else
        {
            ans+=a*b;
            ans+=(b*(b+1))/2;
        }
        return ans;
    }
};