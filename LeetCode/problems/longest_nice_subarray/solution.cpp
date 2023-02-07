class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int temp=0, i=0, ans=0;
        
        for(int j=0;j<nums.size();j++)
        {
            while((temp & nums[j])!=0)
            {
                temp^=nums[i];
                i++;
            }
            temp |= nums[j];
            ans=max(ans, j-i+1);
        }
        return ans;
    }
};