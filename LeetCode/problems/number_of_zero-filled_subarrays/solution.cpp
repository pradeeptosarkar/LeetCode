class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long int ans=0;
        long long int count=0;
        
        for(long long int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count++;
                ans+=count;
            }
            
            else
                count=0;
        }
        
        return ans;
        
    }
};