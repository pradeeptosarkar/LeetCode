class Solution {
public:
    int fib(int n) 
    {
        int fibo[31];
        fibo[0]=0;
        fibo[1]=1;
        
        if(n==0 || n==1)
            return fibo[n];
        
        else
        {
            for(int i=2;i<=n;i++)
                fibo[i]=fibo[i-1]+fibo[i-2];
        }
        
        return fibo[n];
    }
};