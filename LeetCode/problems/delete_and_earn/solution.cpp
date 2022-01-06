class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> total;
        vector<int> v;
        v.push_back(nums[0]);
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                sum += nums[i];
            } else {
                total.push_back(sum);
                sum = nums[i];
                v.push_back(nums[i]);
            }
        }
        total.push_back(sum);
        int a = 0, b = total[0];
        for (int i = 1; i < total.size(); i++) {
            int temp = b;
            if (v[i] != v[i - 1] + 1) {
                b = b + total[i];
            } else {
                b = a + total[i];
            }
            a = temp;
            b = max(a, b);
        }
        return b;
    }
};