class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int ans=0, count=0;
        
        if(nums.size()==0)
            return 0;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==1)
                count++;
            else if(nums[i]-nums[i-1]==0)
                continue;
            else
                count=0;
            ans=max(ans,count);
        }
        return ++ans;
    }
};