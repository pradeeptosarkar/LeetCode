class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> arr(n+1, vector<int>(4,0));
        
        for(int i=0;i<nums.size();i++)
            for(int k=1;k<4;k++)
                arr[i+1][k] = arr[i][k] + (k==nums[i]);                 
            
        int ans=n;
        
        for(int i=0;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=j;k<=n;k++)
                {
                    long int temp = arr[i][1] - arr[i][2] + arr[j][2] - arr[j][3] + arr[k][3];
                    ans = min(ans,n-(int)temp);
                }
            }
        }
        return ans;   
    }
};