class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        deque<pair<int, int>> dp;
        dp.emplace_front(nums[0], 0);
        for (int i = 1; i < nums.size(); i++) {
            while (dp.front().second + k < i) {
                dp.pop_front();
            }
            int cost = dp.front().first + nums[i];
            while (!dp.empty() && cost >= dp.back().first) {
                dp.pop_back();
            }
            dp.emplace_back(cost, i);
        }
        return dp.back().first;
        
    }
};