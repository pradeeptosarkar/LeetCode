class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size() ; 
        int n = grid[0].size() ;
        
        for(int i=m-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                
                int right = INT_MAX ; 
                int down = INT_MAX ; 
                
                if(j+1 < n ){
                    right = grid[i][j+1] ; 
                }
                if(i+1 < m ){
                    down = grid[i+1][j] ; 
                }
                
                
                if(right == INT_MAX && down == INT_MAX ) continue ; 
                grid[i][j] += min (right , down) ; 
                
                
            }
        }
        
        
        return grid[0][0] ; 
    }
};