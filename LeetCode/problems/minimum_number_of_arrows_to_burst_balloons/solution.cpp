class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        
        int n=points.size();
        if(n==1||n==0) return n;
        // sorting based on asc order of ends of balloons
        sort(points.begin(),points.end(),[](auto &v1,auto &v2){
            return v1[1]<v2[1];
        });
        int burstedgrps=0;
        int end=points[0][1];
        for(auto e:points){
            if(e[0]<=end) continue;
            else{
                burstedgrps++;
                end=e[1];
            }
        }
        burstedgrps++; 
        return burstedgrps; // or arrows
    }
};