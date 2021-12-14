class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int ans=0;
        
        if(nums.size()==1)
            return 0;
        
        else if(nums.size()==2)
        {
            if(nums[0]>nums[1])
                return 0;
            
            else
                return 1;
        }
        
        else
        {
            if(nums[0]>nums[1])
                ans=0;
            else if(nums[nums.size()-1]>nums[nums.size()-2])
                ans=nums.size()-1;
            else{
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1])
            {ans=i;
            }
        }
        }
        }
        return ans;
    }
};