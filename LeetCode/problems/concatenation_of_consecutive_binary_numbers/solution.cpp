class Solution {
public:
    
    int concatenatedBinary(int n) 
    {

        const long mod = 1e9+7;

        long pow = 1;

        long res = 0;

        while(n){

            res = (res + n * pow) % mod;

            pow = pow * (1<< binaryLen(n)) % mod;

            n--;

        }

        return res;

    }

    

    int binaryLen(int n){

        int len = 0;

        while(n){

            len++;

            n >>= 1;

        }

        return len;

    }
        
    
};