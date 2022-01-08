class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> countOfNumber;
        for (int n : nums){
            countOfNumber[n]++;
        }
        vector<vector<int>> now = {{}};
        vector<vector<int>> next = {{}};
        
        for(const auto& p : countOfNumber) {
            now = next;
            for(vector<int> v : now) {
                for(int i = 0; i < p.second; i++) {
                    v.push_back(p.first);
                    next.push_back(v);
                }
            }
        }
        return next;
    }
};