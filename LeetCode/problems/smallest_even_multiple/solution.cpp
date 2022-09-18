class Solution {
public:
    int smallestEvenMultiple(int n) 
    {
        if(n==1 or n==2)
            return 2;
        else
        {
            if(n%2)
                return n*2;
            else
                return n;
        }
        
    }
};