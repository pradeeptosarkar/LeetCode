class Solution {
public:
unordered_map<int, int> parent;

void make_set(int val) {
    parent[val] = val;       
}

void union_set(int val1, int val2) {
    int x = find_set(val1);
    int y = find_set(val2);
    if(x != y) {
        parent[y] = x; 
    }
}

int find_set(int val) {
    if(parent[val] == val)
        return val;
    return parent[val] = find_set(parent[val]);
}

bool static cmp(const string& a, const string& b) {
    if(a[1] == '=' and b[1] == '!')
        return 1;
    return 0;
}

bool equationsPossible(vector<string>& equations) {
    sort(equations.begin(), equations.end(), cmp);
    
    for(auto i=0;i<26;i++) {
        make_set(i);
    }
    
    for(auto it:equations) {
        if(it[1] == '!') {
            if(find_set(it[0] - 'a') == find_set(it[3] - 'a'))
                return false;
        }
        else if(it[1] == '=') {
            union_set(it[0] - 'a', it[3] - 'a');
        }
    }
    return true;
}
};