class Solution {
public:
    
    void solve(int& n, vector<vector<string>>& ans, vector<string>& board, vector<int>& left, vector<int>& upperLeft, vector<int>& lowerLeft, int col)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++)
        {
            if(left[row]==0 and upperLeft[n-1+col-row]==0 and lowerLeft[col+row]==0)
            {
                board[row][col]='Q';
                left[row]=1;
                upperLeft[n-1+col-row]=1;
                lowerLeft[col+row]=1;
                
                solve(n, ans, board, left, upperLeft, lowerLeft, col+1);
                
                board[row][col]='.';
                left[row]=0;
                upperLeft[n-1+col-row]=0;
                lowerLeft[col+row]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board (n, string(n,'.'));
        vector<int> left(n, 0), upperLeft(2*n-1, 0), lowerLeft(2*n-1, 0);
        
        solve(n, ans, board, left, upperLeft, lowerLeft, 0);
        return ans;        
    }
};