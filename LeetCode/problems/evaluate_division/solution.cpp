class Solution {
public:
    
    double dfs(const string& start, const string& end, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
    if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
        return -1.0;

    if (start == end)
        return 1.0;

    visited.insert(start);

    for (auto& neighbor : graph[start]) {
        if (visited.find(neighbor.first) == visited.end()) {
            double result = dfs(neighbor.first, end, graph, visited);
            if (result != -1.0)
                return neighbor.second * result;
        }
    }

    return -1.0;
}
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, unordered_map<string, double>> graph;

    for (int i = 0; i < equations.size(); i++) {
        const string& numerator = equations[i][0];
        const string& denominator = equations[i][1];
        double value = values[i];

        graph[numerator][denominator] = value;
        graph[denominator][numerator] = 1.0 / value;
    }

    vector<double> results;

    for (const auto& query : queries) {
        const string& start = query[0];
        const string& end = query[1];
        unordered_set<string> visited;

        double result = dfs(start, end, graph, visited);
        results.push_back(result);
    }

    return results;

    }
};