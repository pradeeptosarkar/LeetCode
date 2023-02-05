class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) 
    {
        map<int, long long> mp;
    
        for(auto i:basket1)
            mp[i]++;
    
        for(auto i:basket2)
            mp[i]--;
    
        long long swaps=0, ans=0;
    
        for(auto[c,count]:mp) 
        {
        
            if(count%2==1)  
                return -1;
        
            swaps+=max((long long)0, count/2);
    
        }
    
        for(auto[c,count]:mp) 
        {
            long long temp = min(swaps, abs(count)/2);
            ans += temp * min(c, begin(mp)->first * 2);
            swaps -= temp;
    
        }
    
        return ans;
        
    }
};