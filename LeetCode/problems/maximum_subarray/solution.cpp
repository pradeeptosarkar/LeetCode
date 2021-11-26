class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        if (nums.size()<0)
          return 0;
          
        int temp=nums[0], max=nums[0];
        
        for (int i=1;i<nums.size();i++)
        {
                        
            if (temp<0)
            {
                temp=0;
            }
            temp+=nums[i];
            if (temp>max)
            {
                max=temp;
            }
                
        }return max;
    }
};