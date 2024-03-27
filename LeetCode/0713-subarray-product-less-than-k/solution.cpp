class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int ans=0;
        int temp=1;
        int i=0, j=0;
        
        while(j<nums.size())
        {
            temp*=nums[j];
            
            while(temp>=k and i<=j)
            {
                temp/=nums[i++];
                //i++;
            }
            
            j++;
            ans+=(j-i);
        }
        
        return ans;
    }
};
