class Solution {
public:
bool isvalid( vector< string > &grid, int row, int col)
{
//check for col
for( int i=row;i>=0;i--)
if(grid[i][col]=='Q')return false;

    //check for left diag
    for( int i=row,j=col;i>=0 and j>=0;i--,j--)
        if(grid[i][j]=='Q')return false;
    
    //check for right diag
   for( int i=row,j=col;i>=0 and j<grid.size();i--,j++)
        if(grid[i][j]=='Q')return false; 
    
    return true;
}

void dfs(  vector< string > &grid, int row, vector< vector< string > > &ret)
{
   if(row==grid.size())  //if row==n that mean we have placed all queens at their corr pos
   {
       ret.push_back(grid);  // push the possible ans int ret vector
       return;
   }
   for( int col=0;col<grid.size();col++){ // check all possiblities int the given row
       if(isvalid(grid,row,col))  //check if it is valid or not
       {
           grid[row][col]='Q';    //place the queen at valid pos
           dfs(grid,row+1,ret);    // solve rest sub problem 
           grid[row][col]='.';    // backtracking 
           
       }
   }   
    
}
vector<vector<string>> solveNQueens(int n) {
    
   vector< string >  grid( n,string(n,'.')); // 2d n*n matrix full of '.' 
   vector< vector< string > > ret;
    dfs(grid,0,ret);
    return ret;
}
};