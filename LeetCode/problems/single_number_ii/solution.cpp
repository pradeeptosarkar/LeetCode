class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans=0;
        
        for(int i=0;i<32;i++)
        {
            int setCount=0;
            
            for(int j=0;j<nums.size();j++)
                setCount+=((nums[j]>>i)&1);
            
            setCount%=3;
            ans|=setCount<<i;
        }
        
        return ans;
    }
};