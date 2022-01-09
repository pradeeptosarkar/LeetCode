class Solution {
public:
    long long int mask;
    
    bool solve(vector<int> &matchsticks, int target, long long mask, int currSum, int i, int k){
        if(k==1) return true; //If the sum is multiple of 4 and already 3 sides are built, then 4th side can be built.
        
        if(currSum==target) 
                return solve(matchsticks, target, mask, 0, 0, k-1);  //If we have built a side, set back the currSum to '0' and start building the next side. 
        
        for(int j=i; j<matchsticks.size(); j++){ //j=i because while building a side, we start traversing the array from where we left off
            
            if((mask&(1<<j))==0 || currSum+matchsticks[j]>target) continue; //If the element is already visited or it's causing the currSum to exceed the target, don't use the element.
            
            mask=mask&~(1<<j);  //If not, mark it as visited and continue.
            if(solve(matchsticks, target, mask, currSum+matchsticks[j], j+1, k))  //continue traversing the other elements with the currSum
                return true;
            mask=mask|(1<<j); //If we returned with a false, that means the curr_element is not working
            
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        if(matchsticks.size()<4||sum%4) return false; //If the elements don't sum to aq multiple of 4, we can't make a square.
        
        mask=(1<<matchsticks.size())-1; //Initially mask=1111... (no. of elements in the array) represents that none of the elements are visited
        return solve(matchsticks, sum/4, mask, 0, 0, 4); //k=4 is the number of sides to build.
    }
};