class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>us(brokenLetters.begin(), brokenLetters.end());
        int ans = 0;
        
        stringstream str(text);
        
        while(1){
            string word;
            getline(str, word, ' ');
            
            if(word.empty()){
                break;
            }
            
            else{
                int flag = true;
                for(char x: word){
                    if(us.find(x) != us.end()){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};