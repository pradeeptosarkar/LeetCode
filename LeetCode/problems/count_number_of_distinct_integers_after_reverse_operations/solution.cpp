class Solution {
public:
    
    int reverse(int n)
    {
        int ans=0;
        
        while(n)
        {
            ans= ans*10 + n%10;
            n/=10;
        }
        return ans;
    }
    
    int countDistinctIntegers(vector<int>& nums) 
    {
        set<int> sett;
        
        for(auto i: nums)
        {
            sett.insert(i);
            sett.insert(reverse(i));
        }
        
        return sett.size();
    }
};