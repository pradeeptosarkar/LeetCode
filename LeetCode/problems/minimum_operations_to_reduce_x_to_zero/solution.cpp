class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int target=0;
        
        for(auto i:nums) 
            target+=i;
        
        target-=x;
        
        if(target<0)
            return -1;
        
        int ans=INT_MIN;
        int j=0;
        int temp=0;
        
        for(int i=0;i<nums.size();i++)
        {
            temp+=nums[i];
            
            while(temp>target)
                temp-=nums[j++];
            
            if(temp==target)
                ans=max(ans, i-j+1);
        }
        
        return ans==INT_MIN ? -1 : nums.size()-ans;
    }
};