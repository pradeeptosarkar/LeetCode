class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n=arr.size();
        vector<int> dp= vector<int>(k+1, 0);
        
        for(int i=n-1;i>=0;i--)
        {
            int tempMax=0, ans=0;
            
            for(int j=i;j<min(n,i+k);j++)
            {
                tempMax=max(tempMax,arr[j]);
                ans=max(ans, (j-i+1)*tempMax+dp[(j+1)%k]);
            }
            
            dp[i%k]=ans;
        }
        
        return dp[0];
    }
};