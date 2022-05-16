class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int canReach=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(canReach<i)
                return false;
            canReach=max(canReach,i+nums[i]);
        }
        return true;
        
    }
};