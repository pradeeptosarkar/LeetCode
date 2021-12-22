#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using rb_tree = tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<long long> buf(nums.size());
    buf[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      buf[i] = buf[i - 1] + nums[i] * 1LL;
    }
    rb_tree _set; _set.insert(0);
    int res = 0;
    for (auto&& val : buf) {
      int r = _set.order_of_key(val - lower + 1LL);
      int l = _set.order_of_key(val - upper);
      res += (r - l);
      _set.insert(val);
    }
    return res;
  }
};