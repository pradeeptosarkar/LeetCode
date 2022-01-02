class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        vector<vector<int>> result = {{rStart,cStart}};
        
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        
        int len = 0, d = 0;
        
        while(result.size()<rows*cols){
            
            if(d==0 || d==2) len++;
            
            for(int i=0;i<len;i++){
                rStart+=dir[d][0];
                cStart+=dir[d][1];
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                    result.push_back({rStart,cStart});
                }
            }
            d = (d+1)%4;
        }
        return result;
    }
};