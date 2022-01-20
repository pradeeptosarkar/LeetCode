class Solution {
public:
    vector<int>poss;
    bool checker(string &s, int st, int en, vector<string>&wordDict) {
        if (st == en)return true;
        bool val = false;
        for (int i = 1; i + st - 1 < en; i++) {
            string k = s.substr(st, i);
            if (find(wordDict.begin(), wordDict.end(), k) != wordDict.end()) {
                // cout << k << endl;
                // cout << st << " " << en << endl;
                if(poss[st+i-1] == -1){
                   val |= checker(s, st + i, en, wordDict);
                   poss[st+i-1] = val;
                }else{
                    val |= poss[st+i-1];
                }
            }
        }
        return val;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        poss.resize(s.length(), -1);
        int st = 0, en = s.length();
        return checker(s, st, en, wordDict);
    }
};