class Trie {
    
    struct TrieNode
    {
        char end='^';
        vector<TrieNode*> next{26,nullptr};
    };
    
    TrieNode* root;
    
public:
    Trie() 
    {
        root = new TrieNode();   
    }
    
    void insert(string word) 
    {
        TrieNode* node=root;
        
        for(char& c:word)
        {
            if(node->next[c-'a']==nullptr)
                node->next[c-'a']= new TrieNode();
            
            node=node->next[c-'a'];
        }
        node->end='*';
    }
    
    bool search(string word) 
    {
        TrieNode* node=root;
        
        for(auto& c:word)
        {
            if(node->next[c-'a']==nullptr)
                return false;
            
            node=node->next[c-'a'];
        }
        
        if(node->end!='*')
            return false;
        
        return true;
        
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* node=root;
        
        for(char&c:prefix)
        {
            if(node->next[c-'a']==nullptr)
                return false;
            
            node=node->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */