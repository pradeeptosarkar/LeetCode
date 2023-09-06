class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int ans=0;
        int curr=0;
        
        for(int i:nums)
        {
            if(i)
                curr+=1;
            
            else
                curr=0;
            
            ans=max(ans,curr);
        }
        
        return ans;
    }
};