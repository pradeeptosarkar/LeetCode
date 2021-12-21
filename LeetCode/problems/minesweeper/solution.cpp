class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
      int Y = board.size(), X = board[0].size();
      vector<vector<char>>table(Y, vector<char>(X,'0'));                                   //for mines in neigbour cells
      vector<vector<int>> d = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
      
      for(int y = 0; y != Y; y++)                                                          //calculate mines in neigbour cells 
        for(int x = 0; x != X; x++)
          if(board[y][x] == 'M')
            for(int w = 0; w < 8; w++){
              int r = y + d[w][0], c = x + d[w][1];
              if( !(r < 0 || c < 0 || r == Y || c == X || board[r][c] == 'M' || board[r][c] == 'X')) table[r][c]++;
            }
      
      if(board[click[0]][click[1]] == 'M') board[click[0]][click[1]] = 'X';             
      else{
        queue<pair<int,int>>q;                                                     //BFS
        q.push({click[0], click[1]});
        while(!q.empty()){
          auto[ty,tx] = q.front();q.pop();          
          if( board[ty][tx] != 'E') continue;
            
          if(table[ty][tx] != '0') board[ty][tx] = table[ty][tx];
          else{
            board[ty][tx] = 'B';
                
            for(int w = 0; w < 8; w++){
              int r = ty + d[w][0], c = tx + d[w][1];
              if( !(r < 0 || c < 0 || r == Y || c == X) ) q.push({r, c});
            }
          }
        }
      }
      
      return board;
  }
};