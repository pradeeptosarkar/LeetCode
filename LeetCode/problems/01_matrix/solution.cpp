class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        //Save all cells of 0 into a queue. Change cells of 1 into INT_MAX.
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = INT_MAX;
            }
        }
        while (!q.empty()) {
            // Get a 0 cell t from queue. 
            pair<int, int> t = q.front(); q.pop();
            // Move to a one step away from this cell. 
            for (auto dir : dirs) {
                int x = t.first + dir[0], y = t.second + dir[1];
                // If it steps out of the matrix, or the adjacent cell already records a smaller distance (for instance, the adjacent cell is also 0). 
                if (x < 0 || x >= m || y < 0 || y >= n || mat[x][y] <= mat[t.first][t.second] + 1) continue;
                // Adds one distance to the adjacent cell.
                mat[x][y] = mat[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
        return mat;
    }
};