class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Create a set for faster word lookup
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        // Create a memoization table to store intermediate results
        unordered_map<string, bool> memo;
        return canSegment(s, wordSet, memo);
    }

    bool canSegment(string s, unordered_set<string>& wordSet, unordered_map<string, bool>& memo) {
        if (s.empty()) {
            return true; // We've successfully segmented the string
        }

        // Check if the result for the current string is already memoized
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }

        // Try to find a word from the dictionary that can be used as a prefix of s
        for (int i = 1; i <= s.length(); i++) {
            string prefix = s.substr(0, i);
            if (wordSet.find(prefix) != wordSet.end()) {
                // If we found a valid word, recursively check the remaining part of the string
                string remaining = s.substr(i);
                if (canSegment(remaining, wordSet, memo)) {
                    memo[s] = true;
                    return true;
                }
            }
        }

        // If no valid segmentation is found, memoize and return false
        memo[s] = false;
        return false;
    }
};
