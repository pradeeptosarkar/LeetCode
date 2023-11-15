class Solution {
public:
    int maxSumRangeQuery(vector<int>& A, vector<vector<int>>& req) {
        long res = 0, mod = 1e9 + 7, n = A.size();
        vector<int> count(n);
        for (auto &r: req) {
            count[r[0]] += 1;
            if (r[1] + 1 < n)
                count[r[1] + 1] -= 1;
        }
        for (int i = 1; i < n; ++i)
            count[i] += count[i - 1];
        sort(begin(count), end(count));
        sort(begin(A), end(A));
        for (int i = 0; i < n; ++i)
            res += (long)A[i] * count[i];
        return res % mod;
    }
};