class Solution {
public:
    int countVowelPermutation(int n) 
    {
        long long mod=pow(10, 9)+7;
        if(n==1)
            return 5;
        vector<unsigned long long> a={1,1,1,1,1};
        vector<unsigned long long> b(5,0);
        
        for(unsigned long long i=2;i<=n;i++)
        {
            b[0]=(a[1]+a[2]+a[4])%mod;
            b[1]=(a[0]+a[2])%mod;
            b[2]=(a[1]+a[3])%mod;
            b[3]=(a[2])%mod;
            b[4]=(a[2]+a[3])%mod;
            a=b;
        }
        
        return (a[0]+a[1]+a[2]+a[3]+a[4])%mod;
        
    }
};