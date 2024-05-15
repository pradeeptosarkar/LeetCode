class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> multiSourceQueue;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    multiSourceQueue.push({i, j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        while (!multiSourceQueue.empty()) {
            int size = multiSourceQueue.size();
            while (size-- > 0) {
                auto curr = multiSourceQueue.front();
                multiSourceQueue.pop();
                
                for (auto& d : dir) {
                    int di = curr.first + d[0];
                    int dj = curr.second + d[1];
                    int val = grid[curr.first][curr.second];
                    
                    if (isValidCell(grid, di, dj) && grid[di][dj] == -1) {
                        grid[di][dj] = val + 1;
                        multiSourceQueue.push({di, dj});
                    }
                }
            }
        }

        priority_queue<vector<int>> pq;
        
        pq.push(vector<int>{grid[0][0], 0, 0}); 
        grid[0][0] = -1; 

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            if (curr[1] == n - 1 && curr[2] == n - 1) {
                return curr[0];
            }

            for (auto& d : dir) {
                int di = d[0] + curr[1];
                int dj = d[1] + curr[2];
                if (isValidCell(grid, di, dj) && grid[di][dj] != -1) {
                    pq.push(vector<int>{min(curr[0], grid[di][dj]), di, dj});
                    grid[di][dj] = -1;
                }
            }
        }

        return -1; 
    }

private:

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isValidCell(vector<vector<int>>& mat, int i, int j) {
        int n = mat.size();
        return i >= 0 && j >= 0 && i < n && j < n;
    }
};
