class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size()==1)return to_string(nums[0]);
if(nums.size()==2)
{
string t=to_string(nums[0])+"/"+to_string(nums[1]);
return t;
}
string res="";
for(int i=0;i<nums.size();i++){
string temp=to_string(nums[i]);
res+=temp+"/";
if(i==0){
res+= "(";
};
}
res.pop_back();
res+=")";
return res;


    }
};