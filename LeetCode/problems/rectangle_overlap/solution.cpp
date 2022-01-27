class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // position of second rectangle w.r.t first rectangle
        
        // right
        if(rec1[2]<=rec2[0]) 
            return false;
        
        // left
        if(rec2[2]<=rec1[0])
            return false;
        
        // top
        if(rec2[1]>=rec1[3])
            return false;
        
        // bottom
        if(rec1[1]>=rec2[3])
            return false;
        return true;
    }
};