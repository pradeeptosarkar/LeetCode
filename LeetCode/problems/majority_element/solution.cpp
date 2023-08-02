class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int temp;
        int cnt=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                temp=nums[i];
                cnt+=1;
            }
                
            else if(temp==nums[i])
                cnt++;
            
            else
                cnt--;
        }
        
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
            if(temp==nums[i])
                ans++;
        
        if(ans>(nums.size()/2))
            return temp;
        
        return -1;
        
    }
};