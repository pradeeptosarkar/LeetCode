class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        //vector<int> dp(n+1);
        //dp[0]=1;
        
        if(n==0)
            return 1;
        
        int dp=1, ans;
        
        int base =9, factor=9;
        
        for(int i=1; i<=n; i++)
        {
            if(i>1)
                base*= factor--;
            
            ans = base + dp;
            dp=ans;
        }
        return ans;
        
    }
};