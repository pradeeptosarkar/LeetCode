class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        size_t l = stoull(left), r = stoull(right);
        int ans = 0;
        
        auto next_palind = [] (string &s) {
            for (int i = s.size() / 2, j = i - (~s.size() & 1); i < s.size(); i++, j--) {
                if (s[i] != '9') {
                    s[i] = s[j] = s[i] + 1;
                    return s;
                }
                s[i] = s[j] = '0';
            }
            s[0] = '1';
            s.push_back('1');
            return s;
        };
        
        auto is_super_root = [] (string &s) {
            size_t num = stoull(s);
            string sqr = to_string(num * num);
            return !sqr.compare({sqr.rbegin(), sqr.rend()});        
        };  
        
        string root("0");
        for (;;) {
            next_palind(root);
            size_t num = stoull(root);
            if (num * num > r) return ans;
            if (num * num >= l) ans += is_super_root(root);
            
        }
        return -1;
    }
};