class Solution {
public:
    int maxSubArray(vector<int>& A) 
    {
        if (A.size()<0)
          return 0;
          
        int n=A.size();
        int loc=0;
        int glob=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            loc=max(A[i], A[i]+loc);
            
            if(loc>glob)
                glob=loc;
        }
        
        return glob;
    }
};