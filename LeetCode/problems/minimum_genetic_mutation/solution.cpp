class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        unordered_set<string> s;
        for(auto b : bank) s.insert(b);
        string acgt = "ACGT";
        queue<string> q;
        q.push(start);
        unordered_map<string, int> m;
        m[start] = 0;
        while(!q.empty()) {
            string str = q.front(); q.pop();
            string r = str;
            for(int i = 0; i < str.size(); i++) {
                str = r;
                for(int j = 0; j < acgt.size(); j++) {
                    str[i] = acgt[j];
                    if(s.count(str) && !m.count(str)) {
                        m[str] = m[r] + 1;
                        if(str == end) return m[str];
                        q.push(str);
                    }
                }
            }
        }
        return -1;
    }
};