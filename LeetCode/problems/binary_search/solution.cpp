class Solution {
public:
    
    int binary_search(vector<int>& nums, int left, int right, int target)
    {
        
        if(left<=right)
        {
            int mid=(left+right)/2;
            
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                return binary_search(nums, left, mid-1, target);
            else
                return binary_search(nums, mid+1, right, target);
        }
       
        return -1;
        
        
    }
    
    int search(vector<int>& nums, int target) 
    {
        int left=0;
        int right=nums.size()-1;
        
        return binary_search(nums, left, right, target);
    }
};