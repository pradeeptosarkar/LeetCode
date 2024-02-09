class Solution {
public:
    
    int robSimple(vector<int>& nums) 
    {
        int n=nums.size();
        
        if(n==1)
            return nums[0];
        
        int a=nums[0];
        int b=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++)
        {
            int c=max(b, a+nums[i]);
            a=b;
            b=c;
        }
        
        return b;
    }
    
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        vector<int> arr1, arr2;
        
        for(int i=0;i<n;i++)
        {
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        
        return max(robSimple(arr1), robSimple(arr2));
    }
};