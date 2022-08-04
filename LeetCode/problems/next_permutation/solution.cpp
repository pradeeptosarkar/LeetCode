class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int a,b;
        
        for(a=nums.size()-2;a>=0;a--)
            if(nums[a]<nums[a+1])
                break;
        
        if(a<0)
            reverse(nums.begin(), nums.end());
        else
        {
            for(b=nums.size()-1;b>a;b--)
                if(nums[b]>nums[a])
                    break;
            
            swap(nums[a], nums[b]);
            reverse(nums.begin()+a+1, nums.end());
        }
    }
};