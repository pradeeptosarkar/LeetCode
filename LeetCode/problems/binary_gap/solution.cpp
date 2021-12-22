class Solution {
public:
    int binaryGap(int n) 
    {
         while(!(n & 1)) // brings 1 to the LSB
            n>>=1;
        int mx=0,zero=-1;
        for(int i=0;i<=31;i++)
        {
            if(n & (1<<i))
            {
                mx=max(mx,zero+1); // counts the max distance between two 1's
                zero=0;
            }
            else
                zero++;
        }
        return mx;  
    }
};