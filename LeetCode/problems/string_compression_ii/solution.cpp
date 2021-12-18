class Solution {
public:
    inline int getLength(int cnt) {
        return cnt == 1 ? 1 : (cnt < 10 ? 2 : (cnt < 100 ? 3 : 4));
    }
    int getLengthOfOptimalCompression(string s, int k) {
        // dp[i][j] is the minimal length of encoding for s[i:] (i included)
        // by deleting at max j characters from s[i:]
        int n = s.size();
        int dp[n+1][k+1];
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                if (i == n) {dp[n][j] = 0; continue;}
                // either delete the ith character (if j > 0)
                dp[i][j] = j > 0 ? dp[i+1][j-1] : INT_MAX;
                // or keep the ith character
                // since we keep, find the index where the group
                // starting with this character would end
                int max_del = j, cnt = 0;
                for (int i_end = i; i_end < n && max_del >= 0; i_end++) {
                    if (s[i_end] == s[i]) {
                        cnt++;
                        // assuming the block ends here
                        dp[i][j] = min(dp[i][j], getLength(cnt) + dp[i_end+1][max_del]);
                    } else {
                        // this character would be deleted
                        max_del--;
                    }
                }
            }
        }
        return dp[0][k];
    }
};