class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int ans=0;
        int currZero=0;
        int currSize=0;
        int left=0, right=0;
        
        while(right<nums.size())
        {
            if(nums[right]==0)
                currZero++;
            
            while(currZero>k)
            {
                if(nums[left]==0)
                    currZero-=1;
                left+=1;
            }
            
            ans=max(ans,right-left+1);
            right++;
        }
        
        return ans;
    }
};