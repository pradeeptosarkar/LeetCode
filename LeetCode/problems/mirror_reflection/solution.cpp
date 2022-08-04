class Solution {
public:
    int mirrorReflection(int p, int q) 
    {
        int m=__gcd(p,q);
        
        p=p/m;
        q=q/m;
        
        if(p%2==0)
            return 2;
        
        return q%2;
        
    }
};