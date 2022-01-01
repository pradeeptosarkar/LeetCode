#define SHIFT 12

class Solution {
public:
  int minSteps(int n) {
    queue<uint> que;
    unordered_set<uint> vis;
    que.push(1U << SHIFT);
    vis.insert(1U << SHIFT);
    int res = 0;
    while (que.size()) {
      int m = que.size();
      while (m--) {
        uint cur = que.front(); que.pop();
        uint x = cur >> SHIFT;
        uint y = cur & ((1U << SHIFT) - 1);
        if (x == n) {
          goto finished;
        }
        if (x + y <= n && vis.find((x + y << SHIFT) + y) == vis.end()) {
          vis.insert((x + y << SHIFT) + y);
          que.push((x + y << SHIFT) + y);
        }
        if (vis.find((x << SHIFT) + x) == vis.end()) {
          vis.insert((x << SHIFT) + x);
          que.push((x << SHIFT) + x);
        }
      }
      res++;
    }
    finished: return res;
  }
};