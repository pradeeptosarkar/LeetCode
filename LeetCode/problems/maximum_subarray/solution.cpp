class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int ans=INT_MIN;
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans, sum+nums[i]);
            sum=max(0, sum+nums[i]);
        }
        return ans;
    }
};