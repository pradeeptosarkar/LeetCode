class Solution {
public:
	int dp[2097152];
	//basically dp size is (2^21)
	bool findans(int m,int desiredTotal,int index){
		bool flag = false;
		//if other player already won
		if(desiredTotal<=0){
			return false;
		}
		if(dp[index]!=-1){
			return dp[index];
		}
		//trying all possibilites
		for(int i=1;i<=m;i++){

			//if bit(number) is currently not picked by anyone and check if player2 lose
			if(((index&1<<i)==0)&&(findans(m,desiredTotal-i,index|(1<<i))==false)){
				//then u win for sure
				return dp[index]=true;
			}
		}
		return dp[index]=false;
	}
	bool canIWin(int m, int desiredTotal) {
		memset(dp,-1,sizeof dp);
		int maxChances = m*(m+1)/2;
		if(m>desiredTotal){
			return true;
		}
		if(desiredTotal <=0 ){
			return true;
		}
		if(maxChances<desiredTotal) {
			return false;
		}
		return findans(m,desiredTotal,0);
	}   
};