class Solution {
public:
    
    int countsetbits(int n)
    {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    
    int countPrimeSetBits(int left, int right) 
    {
        int ans=0,temp=0;
        for(int i=left;i<=right;i++)
        {
            temp=countsetbits(i);
            if(temp==2||temp==3||temp==5||temp==7||temp==11||temp==13||temp==17||temp==19)
                ans++;
        }
        return ans;
    }
};