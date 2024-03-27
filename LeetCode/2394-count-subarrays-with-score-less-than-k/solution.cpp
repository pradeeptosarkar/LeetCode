class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        if(k==1)
            return 0;
        
        long long ans=0, score=0, sum=0;
        
        int i=0, j=0;
        
        while(j<nums.size())
        {
            sum+=nums[j];
            score=sum*(j-i+1);
            
            while(score>=k and i<=j)
            {
                sum-=nums[i++];
                score=sum*(j-i+1);
            }
            
            j++;
            ans+=j-i;
        }
        
        return ans;
    }
};
