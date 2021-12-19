class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int m = coordinates.size();
        
        //slope calculation
        int upper = coordinates[1][1] - coordinates[0][1]  ;
        int lower = coordinates[1][0] - coordinates[0][0];
        
        for(int x=2 ;x<m ;x++){
           int actual_y = coordinates[x][1] ;
           int pred_y ;
            
            //using y value to check all points are on same line
            //equation of line: y = y1 + slope*(x - x1)
            if(lower !=0)
                pred_y=coordinates[0][1] + (upper*(coordinates[x][0] - coordinates[0][0] ) ) / lower;
            
            //using x value to check all points are on same line
            //when line is parallel to y axis
            if(lower == 0){
                int actual_x = coordinates[0][0];
                int pred_x = coordinates[x][0] ;
                if( pred_x != actual_x) return false;
            }
            else if( pred_y != actual_y) return false;
        }
        
        return true;
    }
};