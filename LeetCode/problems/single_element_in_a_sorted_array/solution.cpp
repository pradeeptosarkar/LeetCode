class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1 or nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1];
        
        int left=0, right=n-1;
        
        int mid;
        
        while(left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1])
                return nums[mid];
            
            else if(mid%2==0 and nums[mid]==nums[mid+1] or (mid%2==1 and nums[mid]==nums[mid-1]))
                left=mid+1;
            
            else
                right=mid-1;
        }
        
        return -1;        
    }
};