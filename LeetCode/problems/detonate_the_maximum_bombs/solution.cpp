#define ll long long
class Solution {
public:
    bool isInside(ll circle_x, ll circle_y, ll rad, ll x, ll y){
        if ((x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad) return true;
        else return false;
    }
    
    int bfs(int i, unordered_map<int,vector<int>> &map, int n){
        vector<int> vis(n,false);
        queue<int> q;
        q.push(i);
        vis[i] = true;
        int count=0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            count++;
            for(auto &child : map[cur]){
                if(vis[child]==false){
                    q.push(child);
                    vis[child] = true;
                } 
            }
        }
        return count;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int,vector<int>> map;
        
        for(int i=0; i<n; ++i){
            int circle_x = bombs[i][0];
            int circle_y = bombs[i][1];
            int rad = bombs[i][2];
            for(int j=0; j<n; ++j){
                if(i!=j){
                    int x = bombs[j][0];
                    int y = bombs[j][1];
                    if(isInside(circle_x, circle_y, rad, x, y)) map[i].push_back(j);
                } 
            }
        }
        
        int maxDefuse = 0;
        for(int i=0; i<n; ++i){
            maxDefuse = max(maxDefuse, bfs(i,map,n));
        }
        return maxDefuse;
    }
};