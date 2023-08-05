class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            //int n=nums[i];
            int newTarget=target-nums[i];
            
            if(mp.find(newTarget)!=mp.end())
                return {mp[newTarget], i};
            
            mp[nums[i]]=i;
        }
        
        return {-1,-1};
    }
};