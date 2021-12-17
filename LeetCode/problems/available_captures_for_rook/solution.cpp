class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
      int ri = 0;
        int rj = 0;
        
        //Finding the Bishops Coordinate
        for(int i=0;i<8;i++) {
            for(int j=0 ;j<8;j++) {
                if(board[i][j]  == 'R') {
                   ri = i;
                   rj = j;
                    break;
                }
            }
        }
        int numPawns = 0; //Number of Pawns found so far..
        
        //Finding Pawns in Left Side
        for(int i = ri; i>=0; i--) {
            if(board[i][rj] == 'B') break;
            if(board[i][rj] == 'p') {numPawns++; break;}
        }   
        
        //Finding pawns in Right Side 
        for(int i=rj; i<8;i++) {
          if(board[i][rj] == 'B') break;
          if(board[i][rj] == 'p') {numPawns++; break;}
        }
        
        //Finding Pawns in upward direction
        for(int j = rj; j>=0; j--) {
            if(board[ri][j] == 'B') break;
            if(board[ri][j] == 'p') {numPawns++; break;}
        }
        
        //Finding Pawns in downward direction
        for(int j=rj;j<8;j++) {
            if(board[ri][j] == 'B') break;
            if(board[ri][j] == 'p') {numPawns++; break;}
        }
        
        return numPawns;  
    }
};