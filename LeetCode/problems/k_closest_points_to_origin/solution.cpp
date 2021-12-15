class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int x=points[i][0],y=points[i][1];
            pq.push({-x*x-y*y,{x,y}});
        }
        vector<vector<int>> res;
        vector<int> v(2,0);
        while(pq.empty()==0&&k--){
            v[0]=pq.top().second.first;
            v[1]=pq.top().second.second;
            pq.pop();
            res.push_back(v);
        }
        return res;
    }
};