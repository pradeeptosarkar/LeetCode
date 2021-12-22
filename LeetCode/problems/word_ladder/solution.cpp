class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        unordered_set<string>words;
        for(int i=0;i<wordList.size();i++){
            words.insert(wordList[i]);
        }
        
        if(words.find(end) == words.end()) return 0;
        
        queue<string>q;
        q.push(begin);
        int wordSize = begin.size();
        int ans = 0;
        
        while(!q.empty()){
            ans++;
            int qlen = q.size();
            for(int i=0;i<qlen;i++){
                string s = q.front();
                q.pop();
                for(int j = 0 ; j < wordSize ; j++){
                    char org = s[j];
                    for(char ch = 'a'; ch <= 'z' ; ch++){
                        s[j] = ch;
                        if(s==end) return ans+1;
                        if(words.find(s) == words.end()) continue;
                        words.erase(s);
                        q.push(s);
                    }
                    
                  s[j] = org;  
                }
            }
        }
        return 0;
    } 
};