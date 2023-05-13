class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<long long> temp1(n+1);
        vector<long long> temp2(n+1);
        
        long long ans=0;
        long long pw=1;
        
        for(long long i=0;i<k;i++)
            pw*=2;
        
        temp1[0]=0, temp2[n]=0;
        
        for(long long i=0, j=n-1;i<n;i++, j--)
        {
            temp1[i+1]=temp1[i] | nums[i];
            temp2[j]=temp2[j+1] | nums[j];
        }
            
        
        for(long long i=0;i<n;i++)
            ans=max(ans, temp1[i]|(nums[i]*pw)|temp2[i+1]);
        
        return ans;
    }
};