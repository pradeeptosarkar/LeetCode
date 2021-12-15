class RandomizedCollection {
    unordered_multimap<int,int> m;
    vector<unordered_multimap<int,int>::iterator> v;
    
public:
    RandomizedCollection() {}
    
    bool insert(int val) {
        bool b = !m.count(val);
        v.push_back(m.insert({val, v.size()}));
        return b;
    }
    
    bool remove(int val) {
        if (m.count(val)) {
            unordered_multimap<int,int>::iterator it = m.find(val);
            v.back()->second = it->second;
            swap(v[it->second], v.back());
            m.erase(it);
            v.pop_back();
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        return v[rand() % v.size()]->first;
    }
};