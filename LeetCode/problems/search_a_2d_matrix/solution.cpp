class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int left=0, right=(m*n)-1;
        
        while(left<=right)
        {
            int mid=(right+left)/2;
            int i=mid/n;
            int j=mid%n;
            
            if(matrix[i][j]==target)
                return true;
            
            else if(matrix[i][j]<target)
                left=mid+1;
            
            else
                right=mid-1;
        }
        
        return false;        
    }
};