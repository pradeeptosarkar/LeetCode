class Solution {
public:
    int minCapability(vector<int>& nums, int k) 
    {
        int left=1, right=1e9, n=nums.size();
        
        while(left<right) 
        {
            int mid=(left+right)/2, take=0;
            for (int i=0;i<n;++i)
            {
                if(nums[i]<=mid) 
                {
                    take+=1;
                    i++;
                }
            }

            if(take>=k)
                right=mid;
            else
                left=mid+1;
        }
        return left;
        
    }
};