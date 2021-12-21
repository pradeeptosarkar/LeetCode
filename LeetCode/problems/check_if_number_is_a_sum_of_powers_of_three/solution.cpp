class Solution {
public:
    bool checkPowersOfThree(int n) 
    {
        int rem;
        while(n)
        {
            rem=n%3;
            if(rem>1)
                return false;
            n/=3;
        }
        return true;
    }
};