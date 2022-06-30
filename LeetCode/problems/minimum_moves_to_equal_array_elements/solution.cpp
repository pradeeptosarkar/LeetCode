class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(auto i:nums)
            ans+=abs(i-nums[0]);
        return ans;
        
    }
};