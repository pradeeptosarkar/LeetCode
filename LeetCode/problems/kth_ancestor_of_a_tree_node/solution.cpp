class TreeAncestor {
    vector<vector<int>> dp;

public:
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(n);
        for (auto& i : dp)
            i.resize(31);

        for (int i = 0; i < n; i++) {
            for (int h = 0; h < 31; h++)
                dp[i][h] = -1;
        }

        for (int i = 0; i < n; i++)
            dp[i][0] = parent[i];

        for (int h = 1; h < 31; h++) {
            for (int i = 0; i < n; i++) {
                if (dp[i][h - 1] != -1) {
                    dp[i][h] = dp[dp[i][h - 1]][h - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int ans_node = node;
        int level = k;
        for (int lg = 30; lg >= 0; lg--) {
            if (ans_node != -1 && (1 << lg) <= level) {
                ans_node = dp[ans_node][lg];
                level = level - (1 << lg);
            }
        }

        return ans_node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */