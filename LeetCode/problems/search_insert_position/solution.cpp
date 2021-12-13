class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int a=0, b=nums.size()-1;
        
        if(target<=nums[a])
            return 0;
        
        else if(target==nums[b])
            return b;
        
        else if(target>nums[b])
            return b+1;
        
        else
        {
            while(a<=b)
            {
                int mid=a+(b-a)/2;
            
            if(nums[mid]==target)
                return mid;
            
            else if(nums[mid]<target)
                a=mid+1;
            
            else
                b=mid-1;
            }
        }
        
        return a;
    }
};