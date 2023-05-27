class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        unordered_set<string> dict;

        for (string& word : dictionary) 
            dict.insert(word);
        

        int n = s.length();
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; i++) 
        {
            dp[i] = dp[i - 1] + 1;

            for (int j = i; j >= 1; j--) 
            {
                string temp = s.substr(j - 1, i - (j - 1));

                if (dict.count(temp)) 
                {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
            }
        }

        return dp[n];
        
    }
};