class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int ans=0;
        
        for(int i=0;i<n/2;i++)
            ans=max(ans, nums[i]+nums[n-i-1]);
        
        return ans;
    }
};