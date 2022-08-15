class Solution {
public:
    
    static bool compare(pair<int,int>& w1, pair<int,int>& w2) 
    {
        return w1.second > w2.second;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> heap;
        vector<pair<int,int>> worker; 
        
        for (int i = 0; i < n; i++)
            worker.push_back({speed[i],efficiency[i]});
          
        sort(worker.begin(), worker.end(), compare);
        long res = 0;
        long total = 0;
        long minE;
        for (int i = 0; i < k; i++) 
        {
            total += worker[i].first;
            minE = worker[i].second;
            res = max(res, total*minE);
            heap.push(worker[i].first);
        }
        for (int i = k; i < n; i++) 
        {
            if (worker[i].first > heap.top()) 
            {
                total += (-heap.top()+worker[i].first);
                minE = worker[i].second;
                res = max(res, total*minE);
                heap.pop();
                heap.push(worker[i].first);
            }
        }
        return res % 1000000007;
    }
};