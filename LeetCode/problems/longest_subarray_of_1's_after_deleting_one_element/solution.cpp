class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int ans=0;
        int zeroes=0;
        int start=0;
        
        for(int i=0;i<nums.size();i++)
        {
            zeroes+=(nums[i]==0);
            
            while(zeroes>1)
            {
                if(nums[start]==0)
                    zeroes--;
                start++;
            }
            
            ans=max(ans, i-start);
        }
        
        return ans;
    }
};