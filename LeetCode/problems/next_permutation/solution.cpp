class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int idx=-1;
        
        for(int i=nums.size()-2;i>=0;--i)
            if(nums[i]<nums[i+1])
                {idx=i; break;}
        
        if(idx==-1)
            return sort(nums.begin(), nums.end());
        
        for(int i=nums.size()-1;i>idx;--i)
            if(nums[i]>nums[idx])
                {swap(nums[i], nums[idx]); break;}
        
        sort(nums.begin()+idx+1, nums.end());          
        
    }
};