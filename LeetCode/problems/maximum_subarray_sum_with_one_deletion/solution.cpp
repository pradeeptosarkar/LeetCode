class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (arr.size() <= 1) {
      return arr[0];
    }
    const int n = arr.size();
    int not_delete = max(arr[0] + arr[1], arr[1]);
    int one_delete = max(arr[0], arr[1]);
    int result = max(not_delete, one_delete);
    for (int i = 2; i < n; ++i) {
      one_delete = max(not_delete, one_delete + arr[i]);
      not_delete = max(not_delete + arr[i], arr[i]);
      result = max(result, max(one_delete, not_delete));
    }
    return result;
    }
};