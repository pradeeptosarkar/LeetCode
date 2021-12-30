class Solution {
public:
    int smallestRepunitDivByK(int K) 
    {
       long long  sum=1;
        
        for(int i=1;i<=K;i++)
        {
            if(sum%K==0)
            {
                return i;
            }
            sum=(sum*10+1)%K;
        }
        return -1; 
    }
};