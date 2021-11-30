class Solution {
public:
    bool findrow(vector<char> board){
        bool checknum[10]={0,};
        for(int i = 0 ; i < 9;++i){
            if(board[i] =='.')continue;
            if(checknum[board[i]-'0']) return false;
            checknum[board[i]-'0']= true;
        }
        return true;
    }
    bool findcol(int j,vector<vector<char>> b){
        bool checknum[10]={0,};
        for(int i = 0 ; i < 9;++i){
            if(b[i][j] =='.')continue;
            if(checknum[b[i][j]-'0']) return false;
            checknum[b[i][j]-'0'] = true;
        }
        return true;
    }
    
    bool subboxc(int i ,int j , vector<vector<char>> b){
        bool checknum[10]={false,};
        for(int row = i ; row< i+3; ++row){
            for(int col = j ; col < j+3 ; ++col){
                if(b[row][col] == '.') continue;
                if(checknum[b[row][col] -'0']) return false;
                checknum[b[row][col] -'0'] =true;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
       
        int row = board.size();
        int col = board[0].size();
        for(int i = 0 ; i <row;++i){
            if(!findrow(board[i])) return false;
        }
        
        for(int j = 0 ; j <col;++j){
            if(!findcol(j,board)) return false;
        }
        
        for(int i = 0 ; i < 9; i += 3){
            for(int j = 0 ; j <9; j+=3){
                if(!subboxc(i,j,board)) return false;
            }
        }
        
        return true;
    }
};