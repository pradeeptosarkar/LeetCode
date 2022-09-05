class Solution {
public:
    bool findSubarrays(vector<int>& nums) 
    {
        unordered_set<int> s;
        
        for(int i=1;i<nums.size();++i)
        {
            if(s.find(nums[i-1]+nums[i])==s.end())
                s.insert(nums[i-1]+nums[i]);
            else
                return true;
        }
        return false;
        
    }
};