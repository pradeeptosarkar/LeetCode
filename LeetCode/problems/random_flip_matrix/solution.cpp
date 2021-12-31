class Solution {
private:
    unordered_map<int, int>hashMap;
    int m;
    int n;
    int total;
    
public:
    Solution(int m, int n) : m(m), n(n), total(m * n) {}
    
    vector<int> flip() {
        int y;
        int x = rand() % total;
        int row = x / n;
        int col = x - row * n;            
        
        if(hashMap.find(x) != hashMap.end()){
            y = hashMap[x];
            row = y / n;
            col = y - row * n;
        }
        if(hashMap.find(total - 1) != hashMap.end()){
            hashMap[x] = hashMap[total - 1];
        }
        else{
            hashMap[x] = total - 1;
        }
        total--;
        return vector<int>{row, col};
    }
    
    void reset() {
        hashMap.clear();
        total = m * n;
    }
};