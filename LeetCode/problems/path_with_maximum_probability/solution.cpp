class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            graph[u].push_back({v, prob});
            graph[v].push_back({u, prob});
        }
        
        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        
        priority_queue<pair<double, int>> pq;
        pq.push({dist[start], start});
        
        while (!pq.empty()) {
            pair<double, int> ele = pq.top();
            pq.pop();
            
            double dis = ele.first;
            int node = ele.second;
            
            if (dis > dist[node]) continue;
            if (node == end) return dis;
            
            for (const auto& neighbor : graph[node]) {
                int nei = neighbor.first;
                double newdis = dis * neighbor.second;
                
                if (newdis > dist[nei]) {
                    dist[nei] = newdis;
                    pq.push({dist[nei], nei});
                }
            }
        }
        
        return 0.0;
    }
};
