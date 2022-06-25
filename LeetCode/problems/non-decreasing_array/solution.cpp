class Solution 
{
public:
	
    bool isIncreasing(vector<int> nums) 
    {
        for(int i=1;i<nums.size();i++) 
            if(nums[i]<nums[i-1]) return false;
        
        return true;
    }
    
    bool checkPossibility(vector<int>& nums) 
    {
        for(int i=1;i<nums.size();i++) 
        {
            if(nums[i]<nums[i-1]) 
            {
                int x=nums[i], y=nums[i-1];
				nums[i]=y;
                
                if(isIncreasing(nums)) 
                    return true;
                else 
                {
					nums[i]=x;
                    nums[i-1]=x;
                    return isIncreasing(nums);
                }
            }
        }
        
        return true;
    }
};