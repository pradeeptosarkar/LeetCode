class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].emplace_back(t, y);
            graph[y].emplace_back(t, x);
        }

        vector<int> earliest(n, INT_MAX);
        earliest[0] = 0;
        earliest[firstPerson] = 0;

        stack<pair<int, int>> stack;
        stack.emplace(0, 0);
        stack.emplace(firstPerson, 0);

        while (!stack.empty()) {
            auto [person, time] = stack.top();
            stack.pop();
            for (auto [t, nextPerson] : graph[person]) {
                if (t >= time && earliest[nextPerson] > t) {
                    earliest[nextPerson] = t;
                    stack.emplace(nextPerson, t);
                }
            }
        }

        vector<int> ans;
        
        for (int i = 0; i < n; ++i) 
            if (earliest[i] != INT_MAX) 
                ans.push_back(i);
    
        return ans;
    }
};