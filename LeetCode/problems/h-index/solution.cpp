class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(), c.end());
        int n = c.size();
        if (c[0] >= n) return n;
        for (int i = 1; i < n; i++) {
            int h = n - i;
            if (c[i] >= h && c[i-1] <= h)
                return h;
        }
        return 0;
    }
};