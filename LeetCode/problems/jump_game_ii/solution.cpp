class Solution {
public:
    int jump(vector<int>& nums) {
      int targetindex=nums.size()-1;
        int steps=0;
        while(true){
                if(targetindex==0)break;
            for(int i =0;i<nums.size();i++){
                if(i+nums[i]>=targetindex){
                    steps++;
                    targetindex=i;
                    break;
                }
            }
        }
       return steps;  
    }
};