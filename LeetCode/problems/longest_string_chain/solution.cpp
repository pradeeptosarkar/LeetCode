class Solution {
    static bool compare(string &s1, string &s2){
        return s1.length() < s2.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        
        int ans = 1;
        int n = words.size();
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        
        for(int i = 0 ; i < n ; i++){
            dp[words[i]] = 1;
            int maxPosSubChain = 0;
            for(int j = 0 ; j < words[i].length(); j++){
                string predecessor  = words[i].substr(0, j) + words[i].substr(j+1);
                if(dp.find(predecessor)!=dp.end()){
                    maxPosSubChain = max(maxPosSubChain, dp[predecessor]);
                }
            }
            dp[words[i]] += maxPosSubChain;
            ans = max(ans, dp[words[i]]);
        }        
        
        return ans;
        
    }
};