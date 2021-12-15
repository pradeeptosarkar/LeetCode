class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int idx= -1;                        // for storing index
        int mdis= INT_MAX;                  // we want minimum Manhattan distance
        
        for(int i=0; i<points.size(); i++)
        {
   //if point is valid or not ie it shares same x-coordinate or same y-coordinate as your location.
            if(points[i][0] == x || points[i][1] == y )  
            {
                int dis= abs(x - points[i][0]) + abs(y - points[i][1]);
                if(dis < mdis) {                // we din't use (=) sign to ensure smallest index
                    mdis= dis;
                    idx= i;
                }
            }
        }
        return idx;
    }
};