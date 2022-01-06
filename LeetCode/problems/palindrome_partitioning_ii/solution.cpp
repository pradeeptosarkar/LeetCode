class Solution {
public:
    string s;
    vector<int> mem;
public:
    
    int solve (int i=0) {
        if (i == s.size()) return 0;
        
        if (mem[i] != -1) return mem[i];
        
        int ans = s.size() - 1;
        for (int j = i; j < s.size(); ++j) {
            int st = i, fn = j;
            while (st < fn && s[st] == s[fn]) { ++st; --fn; }
            if (st >= fn) {
                 ans = min(ans, int(j < (s.size() - 1)) + solve (j + 1));
            }
        }
        return mem[i] = ans;
    }   
    
    int minCut(string s_) {
        s = s_; mem = vector<int>(s.size(), -1);
        return solve();
    }
};