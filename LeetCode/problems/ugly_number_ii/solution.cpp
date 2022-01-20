class Solution {
public:
    int nthUglyNumber(int n) {
        // using set to sort and remove duplicate
        set<long long> mset;        
        mset.insert(1);
        n--;
        
        while (n--) {
            auto it = mset.begin();
            long long elem = *it;
            mset.erase(it);            
            mset.insert(elem * 2);
            mset.insert(elem * 3);
            mset.insert(elem * 5);
        }        
        return *mset.begin();        
    }
};