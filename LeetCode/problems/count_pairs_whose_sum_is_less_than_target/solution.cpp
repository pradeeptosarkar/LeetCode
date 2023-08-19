class Solution {
public:
    int countPairs(vector<int>& nums, int target) 
    {
        
        sort(nums.begin(), nums.end()); 
        int ans=0, l=0, r=nums.size()-1;
    
        while(l<r) 
        {
            if (nums[l]+nums[r]<target) 
                ans+=r-l++;
         
            else
                r--;
    }
    
    return ans; 
    }
};