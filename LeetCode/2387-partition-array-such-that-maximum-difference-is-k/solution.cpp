class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        int left=0, right=0;
        int ans=0;
        
        sort(nums.begin(), nums.end());
        
        while(right<nums.size())
        {
            if(nums[right]-nums[left]<=k)
                right++;
            
            else
                ans++, left=right;
        }
        
        return ++ans;
    }
};
