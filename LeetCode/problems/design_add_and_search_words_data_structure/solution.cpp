class WordDictionary 
{

    unordered_map<int, vector<string>> words;
    
    bool isequal(string w1, string w2)
    {
        for(int i=0;i<w1.size();i++)
        {
            if(w2[i]=='.')
                continue;
            if(w1[i]!=w2[i])
                return false;
        }
        return true;
    }
    
    public:
    WordDictionary() {
        
    }
    
    void addWord(string word) 
    {
     
        words[word.size()].push_back(word);
    }
    
    bool search(string word) 
    {
        for(auto s:words[word.size()])
            if(isequal(s,word))
                return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */