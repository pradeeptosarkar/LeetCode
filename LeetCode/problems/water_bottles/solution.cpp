class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int filled=numBottles, empty=0,ans=0;
        
        while(filled>0)
        {
            ans+=filled;
            empty+=filled;
            filled=0;
            filled=empty/numExchange;
            empty-=filled*numExchange;
        }
        return ans;
    }
};