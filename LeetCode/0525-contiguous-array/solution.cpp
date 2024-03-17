class Solution {
public:
    
        int findMaxLength(vector<int>& nums) {
  unordered_map<int,int>m;int r=0;int sum=0;
  for(int i=0;i<nums.size();i++){
       if(nums[i]==1){
            sum=sum+1;
       }
      else{
          sum=sum-1;
      }
      if(m.find(sum)==m.end()){
          m[sum]=i;
          if(sum==0){
              r=max(r,(i+1));
          }
      }
      else{
          if(sum==0){
              r=max(r,i+1);
          }
          else{
              r=max(r,i-m[sum]);
          }
      }
  }
  return r;
}
};
        

