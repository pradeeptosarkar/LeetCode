class Solution {
public:
    int secondHighest(string s) {
        set<int> ss;
        ss.insert(-1);
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])) ss.insert(s[i]-'0');
        }
        set<int>::iterator itr= ss.end();
        --(--itr);
        return *itr;
    }
};