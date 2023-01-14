class Solution {
public:
    int par[26];
    int find_rep(int u) {
        if(par[u] == -1) return u;
        return par[u]= find_rep(par[u]);
    }
    void make_union(int u, int v) {
        u = find_rep(u);
        v = find_rep(v);
        if(u!=v) par[max(u, v)] = min(u, v); 
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(par, -1, sizeof(par));
        for(int i=0; i<s1.size(); i++) make_union(s1[i] - 'a', s2[i] - 'a');
        int n = baseStr.size();
        string ans(n, '.');
        for(int i=0; i<n; i++) ans[i] = find_rep(baseStr[i] - 'a') + 'a';
        return ans;
    }
};