class Solution {
public:
    #define P1_TURN 1
    #define P2_TURN 2
    
    int play2(vector<int> &nums , int left , int right){
        if(left > right) return 0;
        int case1 = nums[left] - play2(nums , left + 1 , right);
        int case2 = nums[right] - play2(nums , left , right - 1);
        return max(case1 , case2);
    }
    int play2_dp(vector<int> &nums){
        vector<vector<int>> dp(50 , vector<int>(50));

        for(int i = 0 ; i < nums.size() ; i++){
            dp[i][i] = nums[i];
        }
        for(int len = 1 ; len < nums.size() ; len++){
            for(int i = 0 ; i < nums.size(); i++){
                int j = i + len;
                if(j < i || j >= nums.size()) continue;
                dp[i][j] = max(nums[i] - dp[i + 1][j] , nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][nums.size() - 1] >= 0;
    }
    bool play(vector<int>& nums ,int p1_score , int p2_score , int turn , int left , int right){
        
        if(left > right){
            return p1_score>=p2_score;
        }
        
        if(turn == P1_TURN){
            bool case1 = play(nums , p1_score+nums[left] , p2_score , P2_TURN , left+1 , right);
            bool case2 = play(nums , p1_score+nums[right] , p2_score , P2_TURN , left , right-1);
            return case1 || case2;
        }
        else{
            bool case1 = play(nums , p1_score,p2_score+nums[left] , P1_TURN,left+1,right);
            bool case2 = play(nums , p1_score, p2_score+nums[right] , P1_TURN , left, right-1);
            //here case1 and case2 returns the winning status of player 1
            //and if any of case1 or case2 returns false then player 2 will play that one
            //that's why the && operator
            return case1 && case2;
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        // return play(nums , 0 , 0, P1_TURN , 0 , nums.size()-1);
        // return play2(nums , 0 , nums.size() - 1) >= 0;
        return play2_dp(nums);
    }
};