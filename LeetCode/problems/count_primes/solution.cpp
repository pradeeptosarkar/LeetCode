class Solution {
public:
    int countPrimes(int n) 
    {
        vector<bool> sieve(n+1,0);
        
        int count=0, i=2;
        
        while(i<n)
        {
            if (!sieve[i]) 
            {
            count++;

            for (int j = i; j < n; j += i)
            {sieve[j]=1;}
            }
            
            i++;     
        }
        
        return count;
    }
    };