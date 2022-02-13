class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int text1Len = text1.size();
        int text2Len = text2.size();
        
        // i: index of text1
        // j: index of text2
        // dp[i][j] is the length of the longest common subsequence 
        // of text1[0..i-1] and text2[0..j-1].
        vector<vector<int>> dp(text1Len + 1, vector<int>(text2Len + 1, 0));
        
        for (int i = 1; i <= text1Len; ++i) {
            for (int j = 1; j <= text2Len; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[text1Len][text2Len];
    }
};