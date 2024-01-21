class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        int a,b,c;
        
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        
        a=0;
        b=0;
        
        for(int i=0;i<n;i++)
        {
            int c=b+nums[i];
            int d=max(a,b);
            
            a=c;
            b=d;
        }
            
        return max(a,b);
    }
};