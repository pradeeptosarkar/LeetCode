class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val)){
            return false;
        }
        m[val]=v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val))
            return false;
        else{
            int lastnum=v[v.size()-1];
            swap(v[m[val]],v[v.size()-1]);
            v.pop_back();
            m[lastnum]=m[val];
            m.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int sz=v.size();
        int rnum=rand()%sz;
        return v[rnum];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */