class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
     if(k==0||n>=k+maxPts)
            return 1.0;
        int maxRange=k-1+maxPts;
        vector<double>current_prob(maxRange+1,0);
        current_prob[0]=1.0;
        double runningsum=current_prob[0];
        double result=0.0;
        for(int i=1;i<=n;i++){
            current_prob[i]=runningsum/(double)maxPts;
            
            //handle the front end of the running sum
            if(i<k){
                runningsum+=current_prob[i];
            }
            else
                result+=current_prob[i];
            //tail end of the running sum
            if(i-maxPts>=0){
                runningsum-=current_prob[i-maxPts];
            }
        }
        
        return result;   
    }
};