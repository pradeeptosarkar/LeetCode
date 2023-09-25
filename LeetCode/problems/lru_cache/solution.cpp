class LRUCache {
public:
    
    class node
    {
        public:
        int key;
        
        int value;
        node* next;
        node* prev;
        
        node(int k, int v)
        {
            key=k;
            value=v;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;
    
    void addNode(node* newNode)
    {
        node* temp=head->next;
        
        head->next=newNode;
        newNode->prev=head;
        newNode->next=temp;
        temp->prev=newNode;
    }
    
    void delNode(node* oldNode)
    {
        node* a=oldNode->prev;
        node* b=oldNode->next;
        
        a->next=b;
        b->prev=a;
    }
    
    LRUCache(int capacity) 
    {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) 
    {
        if(mp.find(key)!=mp.end())
        {
            node* ansNode=mp[key];
            int ans=ansNode->value;
            mp.erase(key);
            delNode(ansNode);
            addNode(ansNode);
            mp[key]=head->next;
            return ans;
        }
        
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            node* ansNode=mp[key];
            mp.erase(key);
            delNode(ansNode);
        }
        
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        
        addNode(new node(key, value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */