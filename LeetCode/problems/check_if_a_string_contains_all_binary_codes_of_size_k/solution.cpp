class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k)    
            return false;
        unordered_set<string> store;
        for(int i=0;i<=s.length()-k;i++)
            store.insert(s.substr(i,k));
        return store.size() == pow(2,k);

    }
};