class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
      
      int n=mat.size();
      int m=mat[0].size();
      int cLow=0;
      int cHigh=m-1;
      while(cLow<=cHigh) 
      {
       int mid=cLow+(cHigh-cLow)/2;
        int max_i=0;       
        for(int i=0;i<n;i++)  //finding the global max on that row;;;
        {
          max_i = (mat[i][mid] >= mat[max_i][mid]) ? i : max_i ;
        }
        bool bigLeft = (mid-1 >= cLow) && (mat[max_i][mid-1]>mat[max_i][mid]);
         bool bigRight = (mid+1 <= cHigh) && (mat[max_i][mid+1]>mat[max_i][mid]);
        if(!bigRight && !bigLeft)
        {
           return vector<int>{ max_i, mid};
        }
        else if(bigRight){
          cLow=mid+1;
        }
        else
          cHigh=mid-1;
      }
     return vector<int>{-1,-1};
      
    }
};