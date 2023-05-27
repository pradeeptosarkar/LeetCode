class Solution {
public:
    long long maxStrength(vector<int>& nums) 
    {
    
        int n=nums.size();
        
        if(n==1)
            return nums[0];
        
        long long ans=1, count0=0, count1=0, count2=0;
        int maxi=INT_MIN;
        
        for(auto i:nums)
        {
            if(i==0)
            {
                count0++;
                continue;
            }
            
            if(i<0)
            {
                count1++;
                maxi=max(maxi,i);
            }
            
            else
            {
                count2++;
            }
            ans*=abs(i);
        }
        
        if(count0==n) return 0;
        
        if(count1+count0==n and count1==1) return 0;
        
        if(count1%2==0)
            return ans;
        else
            return(ans/abs(maxi));
    }
};