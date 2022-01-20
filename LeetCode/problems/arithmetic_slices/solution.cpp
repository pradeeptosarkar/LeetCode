class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n = nums.size();
    if(n < 3)return 0;
    int diff = INT_MIN;
    int ct = 1;
    int ans = 0;
    
    for(int i=1 ; i<n ; i++){
        if(diff == INT_MIN){
            diff = nums[i] - nums[i-1];
            ct++;
            continue;
        }
        if(nums[i] - nums[i-1] == diff){
            ct++;
        }else{
            if(ct > 2){
                ans += ((ct-2) * (ct-1))/2;
            }
            ct = 1;
            diff = INT_MIN;
            i--;
        }
    }
    if(ct > 2){
        ans +=((ct-2) * (ct-1))/2;
        
    }
    
    return ans;  
    }
};