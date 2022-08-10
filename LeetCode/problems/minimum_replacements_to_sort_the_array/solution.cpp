class Solution {
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        long long ans=0;
        long long n=nums.size();
        
        for(int i=n-2;i>=0;i--)
        {
            ans+=ceil(nums[i]*1.00/nums[i+1])-1;
            nums[i]/=ceil(nums[i]*1.00/nums[i+1]);
        }
        return ans;
    }
};