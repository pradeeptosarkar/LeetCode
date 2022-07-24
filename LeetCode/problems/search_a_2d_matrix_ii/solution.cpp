class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int c=n-1;
        int r=0;
        
        while(r<m and c>=0)
        {
            if(matrix[r][c]==target)
                return true;
            else if(matrix[r][c]<target)
                r++;
            else
                c--;
        }
        return false;   
        
    }
};