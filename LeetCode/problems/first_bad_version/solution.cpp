// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int a=1,b=n;
        
        int pos=1;
        
        while(a<=b)
        {
          
            int mid=a+(b-a)/2;
           
            if(isBadVersion(mid)==true)
            {
                pos=mid;
                b=mid-1;
            }
            else
                a=mid+1;
        }

        // return the first index of faulty product
        return pos;
    }
};