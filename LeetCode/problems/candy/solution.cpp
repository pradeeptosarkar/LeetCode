class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<vector<int>>graph(n);
        vector<int>indegree(n,0);
        vector<int>points(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                graph[i-1].push_back(i);
                indegree[i]++;
            }
            else if(ratings[i]<ratings[i-1]){
                graph[i].push_back(i-1);
                indegree[i-1]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(q.size()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int curr = q.front();q.pop();
                for(auto&adj:graph[curr]){
                    if(--indegree[adj]==0){
                        q.push(adj);
                    }
                    points[adj] = max(points[adj],points[curr]+1);
                }
            }
        }
        int result = 0;
        for(int i=0;i<n;i++){
            result+=points[i];
        }
        return result;
    }
};