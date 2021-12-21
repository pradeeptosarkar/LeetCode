class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0, freshLeft = 0;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        //Save all cells of rotten oranges into a queue.
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) freshLeft++;
            }
        }
        while (!q.empty() && freshLeft > 0) {
            // Record how many rounds the transmission has occured. 
            for (int i = q.size(); i > 0; --i) {
                // Get a 0 rotten orange cell t from queue. 
                pair<int, int> t = q.front(); q.pop();
                // Move to a one step away from this cell. 
                for (auto dir : dirs) {
                    int x = t.first + dir[0], y = t.second + dir[1];
                    // If it steps out of the matrix, or the adjacent cell is a rotten orange, or there is no orange there. 
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) continue;
                    // The adjacent cell is rotten now.
                    grid[x][y] = 2;
                    q.push({x, y});
                    freshLeft --; 
                }
            }
            res++;
        }
        return freshLeft > 0? -1: res;

    }
};