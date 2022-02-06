class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int len = nums.size();
        int i;
        int ans = 1;
        int length = 1;
        for(i = 0;i<len-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                length++;
            }
            else
            {
                ans = max(ans,length);
                length = 1;
            }
        }
        return max(ans,length);
        
    }
};