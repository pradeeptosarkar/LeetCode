class Solution {
private:
    unordered_map<int, vector<int>> m;
public:
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        auto picked = m[target];
        int n = picked.size();
        return picked[rand()%n];
    }
};