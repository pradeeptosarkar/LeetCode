class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1); 
        
        bool rect2_left_of_rect1 = (ax1 >= bx2);
        bool rect2_right_of_rect1 = (ax2 <= bx1);
        bool rect2_above_of_rect1 = (ay2 <= by1);
        bool rect2_below_of_rect1 = (ay1 >= by2);
        
        if(rect2_left_of_rect1 || rect2_right_of_rect1 || rect2_above_of_rect1 || rect2_below_of_rect1) 
            return area1 + area2; //no overlap 
        int overlap_area = (min(bx2,ax2) - max(bx1,ax1)) * (min(ay2,by2) - max(ay1,by1));
        return area1 + area2 - overlap_area;
    }
};