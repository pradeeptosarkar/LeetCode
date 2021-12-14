class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
       vector<int> result;
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return result;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dirs = { {-1, 1}, {1, -1} };

    int row = 0; int col = 0; int d = 0;

    for (int i = 0; i < m * n; i++) {
        result.push_back(matrix[row][col]);
        row += dirs[d][0];
        col += dirs[d][1];

        if (row >= m) { row = m - 1; col += 2; d = 1 - d;}
        if (col >= n) { col = n - 1; row += 2; d = 1 - d;}
        if (row < 0)  { row = 0; d = 1 - d;}
        if (col < 0)  { col = 0; d = 1 - d;}

    }

    return result; 
    }
};