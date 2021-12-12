class Solution {
public:
    int findIntegers(int num) {
          if(num == 0)    return 1;
        if(num == 1)    return 2;
        vector<int> dp(32,0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2; i<32; i++)		//Find the number of i digits, the number of non-negative integers without consecutive 1s
            dp[i] = dp[i-1]+dp[i-2];
        int ans=1,i=30;
        bool pause=false;
        while(i>=0){
            if((num&(1<<i)) != 0){
                ans += dp[i];
                if(pause){
                    ans--;		//itself contains continuous 1, so you have to remove your own 
                    break;
                }
                pause = true;
            }else   pause=false;
            i--;
        }
        return ans;
    }
};