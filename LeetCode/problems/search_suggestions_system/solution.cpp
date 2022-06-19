class TrieNode{
    public:
    TrieNode* child[26];
    vector<int> indices;
    
    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
        
        indices={};
    }
};
class Trie{
    public:
    TrieNode* root = new TrieNode();
    int i=0;
    
    void insert(string word, int index)
    {
        if(i==word.length())
            return;
        
        TrieNode* curr_node = root;
        
        if(root->child[word[i]-'a']==NULL)
        {
            TrieNode* newNode = new TrieNode();
            root->child[word[i]-'a']=newNode;
        }
        
        root=root->child[word[i]-'a'];
        root->indices.push_back(index);
        i++;
        
        insert(word,index);
        
        root=curr_node;
        i--;
    }
    
    void search(string word, vector<vector<int>> &ans)
    {
        if(i==word.length())
            return;
        
        TrieNode* curr_node = root;
        
        if(root->child[word[i]-'a']==NULL)
            return;
        
        root=root->child[word[i]-'a'];
        ans.push_back(root->indices);
        i++;
    
        search(word,ans);
        
        root=curr_node;
        i--;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(),products.end());
        
        Trie* trie_of_products = new Trie();
        
        int n=products.size();
        
        for(int i=0;i<n;i++)
        {
            trie_of_products->insert(products[i],i);
        }
        
        vector<vector<int>> ans;
        
        trie_of_products->search(searchWord,ans);
        
        n=searchWord.length();
        
        while(ans.size()<n)
        {
            ans.push_back({});
        }
        
        vector<vector<string>> search_result;
        
        for(int i=0;i<ans.size();i++)
        {
            set<int> st;
            
            for(int j=0;j<ans[i].size();j++)
            {
                st.insert(ans[i][j]);
                
                while(st.size()>3)
                {
                    auto it = st.end();
                    it--;
                    
                    st.erase(it);
                }
            }
            
            vector<string> v;
            
            for(auto &x: st)
            {
                v.push_back(products[x]);
            }
            
            search_result.push_back(v);
        }
        
         return search_result;
    }
    
   
};