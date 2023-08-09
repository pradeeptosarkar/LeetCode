class Solution {
public:
    
    int count(vector<int> &nums, int check, int n)
    {
        int ans=0, i=0;
        
        while(i<n-1)
        {
            if(nums[i+1]-nums[i]<=check)
                ans++, i++;
            
            i++;
        }
        
        return ans;
    }
    
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        int left=0, right=nums[n-1]-nums[0];
        
        while(left<right)
        {
            int mid = left+(right-left)/2;
            
            if(count(nums,mid,n)>=p)
                right=mid;
            else
                left=mid+1;
        }
        
        return left;
    }
};