class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int sizeN{(int)nums.size()}, sizeM{(int)multipliers.size()}, max_{INT32_MIN};

        std::vector<std::vector<int>> dp(sizeM+1, std::vector<int>(sizeM+1, 0));

        for(int i{1}; i <= sizeM; ++i) dp[i][0] = multipliers[i-1] * nums[i-1] + dp[i-1][0];

        for(int j{1}; j <= sizeM; ++j) dp[0][j] = multipliers[j-1] * nums[sizeN-j] + dp[0][j-1];

        

        for(int i{1}; i <= sizeM; ++i) {

            for(int j{1}; j+i <= sizeM; ++j) {

                dp[i][j] = std::max(multipliers[i+j-1]*nums[i-1] + dp[i-1][j], multipliers[i+j-1]*nums[sizeN-j] + dp[i][j-1]);

            }

            max_ = std::max(max_, dp[i][sizeM-i]); // maxum product using M numbers, with i of them are on the left.

        }

        return max_;
    }
};