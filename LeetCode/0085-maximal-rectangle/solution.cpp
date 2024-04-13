class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();
    if (cols == 0) return 0;
    vector<int> left(cols, 0);
    vector<int> right(cols, cols);
    vector<int> height(cols, 0);
    int area = 0;
    for (int i = 0; i < rows; ++i) {
      int current_left = 0;
      int current_right = cols;
      for (int j = 0; j < cols; ++j) {
        if (matrix[i][j] == '1') {
          ++height[j];
          left[j] = max(left[j], current_left);
        } else {
          height[j] = 0;
          left[j] = 0;
          current_left = j + 1;
        }
      }
   
      for (int j = cols - 1; j >=0; --j) {
        if (matrix[i][j] == '1') {
          right[j] = min(right[j], current_right);
        } else {
          right[j] = cols;
          current_right = j;
        }
      }
      for (int j = 0; j < cols; ++j) 
        area = max(area, (right[j] - left[j]) * height[j]);
    }
    return area;
  }
};
