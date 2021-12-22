class Solution {
public:
    int bitwiseComplement(int n) 
    {
        if(n==0)
            return 1;
        
        int count=0,num=n;
        
        while(num!=0)
        {
            num/=2;
            count++;
        }
        
        int high=pow(2,count)-1;
        return high-n;
    }
};