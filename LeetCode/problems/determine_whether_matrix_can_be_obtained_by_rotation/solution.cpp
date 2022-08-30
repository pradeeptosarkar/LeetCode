class Solution {
public:
    
    void rotate(vector<vector<int> >& matrix)
    {
    
        int rows = matrix.size();
        int cols = matrix[0].size();
    
        for(int i = 0 ; i < rows; i++)
            for( int j = 0 ; j < i ;j++)
                swap(matrix[i][j], matrix[j][i]) ;  
        
        for(auto &row : matrix)        
            reverse(row.begin(), row.end());
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
    {
        for(int i=0 ; i< 4;i++)
        {
            if(mat == target)
                return true ;
            
            rotate(mat) ;
        }
        return false ;
    }
};