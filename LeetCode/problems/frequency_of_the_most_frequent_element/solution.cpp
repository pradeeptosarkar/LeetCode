class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int left=0;
        long long temp=0;
        
        for(int right=0;right<nums.size();right++) 
        {
            long target=nums[right];
            temp+=target;
            
            if((right-left+1)*target-temp>k) 
            {
                temp-=nums[left];
                left++;
            }
        }
        
        return nums.size()-left;
    }
};