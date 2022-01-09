class Solution {
    
     bool checkD(vector<vector<int>>& grid, int i, int j, int l, int& sum){
        
        int lds = i;
        int ldsj = j;
         int lsum = 0;
         for(int k = 0;k<l;k++){
             lsum = lsum + grid[lds][ldsj];
             lds = lds + 1;
             ldsj = ldsj +1;
         }
         if(lsum!=sum)
             return false;
         
         
          int rds = i;
        int rdsj = j+l-1;
         int rsum = 0;
         for(int k = 0;k<l;k++){
             rsum = rsum + grid[rds][rdsj];
             rds = rds + 1;
             rdsj = rdsj -1;
         }
         
         if(rsum!=sum)
             return false;
         
         return true;
         
    }
    
    
    
    bool checkCol(vector<vector<int>>& grid, int i, int j, int l, int& sum){
        
        int er = i+l-1;

        int t;
        for(int c = j;c<=j+l-1;c++){
            if(i==0){
               t =  grid[er][c];
            }else{
                t = grid[er][c] - grid[i-1][c];
            }
            if(t!=sum)
                return false;
        }
        return true;
    }
    
    
    
    bool checkRow(vector<vector<int>>& grid, int i, int j, int l, int& sum){
        
        int ec = j+l-1;
        if(j!=0)
            sum = grid[i][ec] - grid[i][j-1];
        else
             sum = grid[i][ec];
        int t;
        for(int r = i;r<=i+l-1;r++){
            if(j==0){
               t =  grid[r][ec];
            }else{
                t = grid[r][ec] - grid[r][j-1];
            }
            if(t!=sum)
                return false;
        }
        return true;
    }
    
    
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
     
        int m = grid.size();
        int n = grid[0].size();
        int maxm = min(m,n);

        vector<vector<int>> prefixGridRow(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>> prefixGridCol(grid.size(),vector<int>(grid[0].size(),0));
        
         for(int i=0;i<m;i++){
             
           for(int j=0;j<n;j++){
                if(j==0)
                    prefixGridRow[i][j] = grid[i][j];
                else
                    prefixGridRow[i][j] = prefixGridRow[i][j-1] + grid[i][j];
           }
            
         }
        
        
        for(int i=0;i<m;i++){
             
           for(int j=0;j<n;j++){
                if(i==0)
                    prefixGridCol[i][j] = grid[i][j];
                else
                    prefixGridCol[i][j] = prefixGridCol[i-1][j] + grid[i][j];
           }
            
         }
        
        int ans = 1;
        int sum = 0;
        for(int l = 1;l<=maxm;l++){
            for(int i=0;i<m-l+1;i++){
                for(int j=0;j<n-l+1;j++){
                    if(checkRow(prefixGridRow, i, j, l, sum) && checkCol(prefixGridCol, i, j, l, sum) && checkD(grid, i, j, l, sum)){
                        ans = max(ans, l);
                    }
                }
            }
        }
        return ans;
    }
};