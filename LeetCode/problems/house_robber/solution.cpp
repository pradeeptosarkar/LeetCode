class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
    
        if(n==0) 
        return 0;
    
        if(n==1) 
        return nums[0];
        
        int a[n];
        a[0]=nums[0];
        a[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        a[i]=max(nums[i]+a[i-2], a[i-1]);
        return a[n-1];
    }
};