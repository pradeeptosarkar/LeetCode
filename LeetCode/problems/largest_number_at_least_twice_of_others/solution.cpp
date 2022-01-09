class Solution {
public:
    int dominantIndex(vector<int>& nums) 
    {
        int a=0;
        int b=0;
        
        for(int i=1;i<nums.size();i++)
            if(nums[i]>nums[a])
                a=i;
        
        int largest=nums[a];
        nums[a]=-1;
        
        for(int i=1;i<nums.size();i++)
            if(nums[i]>nums[b])
                b=i;
        
        if(largest>=(2*nums[b]))
            return a;
        else
            return -1;
    }
};