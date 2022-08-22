class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        if(n<=0)
            return false;
            
        if(n==1)
            return true;
        
        if(n & n-1)
            return false;
        
        int c;
        
        while(!(n&1))
        {
            c++;
            n=n>>1;
        }
        
        if((c&1)==0)
            return true;
        
        return false;
        
    }
};