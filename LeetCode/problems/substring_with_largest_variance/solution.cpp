int FindVariance(const vector<int>& indices_x, const vector<int>& indices_y) {
  int variance = 0;
  int low = indices_y.size();
  int new_low = 0;
  int diff = 0;
  auto it = indices_y.begin();
  for (int index_x : indices_x) {
    while (it != indices_y.end() && *it < index_x) {
      ++it;
      ++diff;
    }
    variance = max(variance, diff - low);
    --diff;  // Now diff includes index_x
    low = min(low, new_low);
    new_low = diff;  // This one cannot be used in the next index_x.
    if (it == indices_y.end()) {
      break;
    }
  }
  diff += indices_y.end() - it;
  variance = max(variance, diff - low);
  return variance;
}

class Solution {
public:
  int largestVariance(string s) {
    vector<int> indices[26];
    for (int i = 0; i < s.size(); ++i) {
      indices[s[i] - 'a'].push_back(i);
    }
    int answer = 0;
    for (const vector<int>& indices_x : indices) {
      if (indices_x.empty()) {
        continue;
      }
      for (const vector<int>& indices_y : indices) {
        if (indices_y.empty() || &indices_y == &indices_x) {
          continue;
        }
        answer = std::max(answer, FindVariance(indices_x, indices_y));
      }
    }
    return answer;
  }
};