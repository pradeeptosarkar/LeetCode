class Solution {

    int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    

public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] || grid[n-1][n-1]) return -1;

        queue<pair<int, int>> q;

        int level = 0;

        q.push({0, 0});

        grid[0][0] = 1;

        while (!q.empty()) {

            level++;

            int sz = q.size();

            while (sz--) {

                int i = q.front().first, j = q.front().second;

                q.pop();

                if (i == n-1 && j == n-1)

                    return level;

                for (int k = 0; k < 8; k++) {

                    int ni = i + di[k];

                    int nj = j + dj[k];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 0) {

                        grid[ni][nj] = 1;

                        q.push({ni, nj});

                    }

                }

            }

        }

        return -1;

    }

};
        
