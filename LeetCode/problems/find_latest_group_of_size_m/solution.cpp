class Solution {
    int find(int f, vector<int>& uf) {
        return uf[f] < 0? f : uf[f] = find(uf[f], uf);
    }
    void uni(int a, int b, vector<int> &uf, int &cur, int m) {
        if(a == b) return;
        if(uf[a] == -m) --cur;
        if(a > b)
            swap(a,b);
        uf[a] += uf[b];
        uf[b] = a;
    }
public:
    int findLatestStep(vector<int>& arr, int m) {
        vector<int> uf(arr.size()+1, -1);
        unordered_set<int> seen;
        int track = 0, ans = -1, cur = 0;
        for(int i=0; i<arr.size(); i++) {
            seen.insert(arr[i]);
            if(seen.find(arr[i]-1) != seen.end())
                uni(find(arr[i]-1, uf), find(arr[i],uf), uf, cur, m);
            if(seen.find(arr[i]+1) != seen.end())
                uni(find(arr[i]+1,uf), find(arr[i],uf), uf, cur, m);
            if(uf[find(arr[i], uf)] == -m) cur++;
            if(cur) ans = i+1;
        }
        return ans;
    }
};