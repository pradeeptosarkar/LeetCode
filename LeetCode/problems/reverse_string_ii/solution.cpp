class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2*k) {
            k = min((size_t)k, s.size()-i);
            for (int j = 0; j < k/2; j++) {
                swap(s[i+j], s[i+k-j-1]);
            }
        }
        
        return s;
    }
};