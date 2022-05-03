class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        if(nums.size()==1)
            return 0;
        
        int n=nums.size();
        int ans=n;
        int left=0, right=n-1;
        
        while(left<=right)
        {
            if(nums[left]==*min_element((nums.begin()+left),(nums.begin()+right+1)) and nums[right]==*max_element((nums.begin()+left),(nums.begin()+right+1)))
                left++, right--, ans-=2;
            
            else if(nums[left]==*min_element((nums.begin()+left),(nums.begin()+right+1)))
                left++, ans-=1;
            
            else if(nums[right]==*max_element((nums.begin()+left),(nums.begin()+right+1)))
                right--, ans-=1;
            
            else
                return ans;
        }
        if(ans<0)
            return 0;
        else
            return ans;
        
        
    }
};