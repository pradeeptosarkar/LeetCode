class Solution {
public:
    string pushDominoes(string d) 
    {
        int n = d.size();
        
        vector<int> state(n, 0); // 0 -> standing, -1 -> L, 1 -> R 
        vector<bool> visited(n, false);
        
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (d[i] == '.') continue;
            
            if (d[i] == 'L') state[i] = -1; 
            else if (d[i] == 'R') state[i] = 1;
            
            visited[i] = true;
            q.push(i);
        }
        
        while (not q.empty()) {
            int len = q.size();
            vector<int> temp;
            
            for (int i=0; i<len; i++) {
                int pos = q.front(); q.pop();
                
                if (state[pos] == -1) { // fall left 
                    if (pos > 0 and not visited[pos-1]) {
                        temp.push_back(pos-1);
                        state[pos-1] -= 1;
                    }
                } else if (state[pos] == 1) { // fall right
                    if (pos < n-1 and not visited[pos+1]) {
                        temp.push_back(pos+1);
                        state[pos+1] += 1;
                    }
                }
            }
            
            for (auto pos: temp) {
                visited[pos] = true;
                if (state[pos] != 0) q.push(pos); // add dominos to queue only if they are tilting toward one side
            }
        }
        
        string ret(n, '.'); 
        for (int i=0; i<n; i++) {
            if (state[i] == -1) ret[i] = 'L';
            else if (state[i] == 1) ret[i] = 'R';
        }
        
        return ret;
    }
};