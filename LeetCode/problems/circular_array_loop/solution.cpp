class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
                
int n = nums.size();
        vector<vector<int>> g(n);
        vector<int> inD(n);
        for (int i = 0; i < n; i++) {
            int p = ((i + nums[i]) % n + n) % n;
            if (p == i || nums[i] * nums[p] < 0) continue;
            g[i].push_back(p);
            inD[p]++;
        }
        deque<int> collec;
        for (int v = 0; v < n; v++)
            if (inD[v] == 0) collec.push_back(v);
        int cnt = 0;
        while (!collec.empty()) {
            auto v = collec.front();
            collec.pop_front();
            for (auto & node : g[v])
                if (--inD[node] == 0) 
                    collec.push_back(node);
            cnt++;
        }
        return !(cnt == n);
    }
};