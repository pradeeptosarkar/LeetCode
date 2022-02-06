class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int count = 0, k=0, n=nums.size();
    int a = nums[0];
    for(int i=0;i<nums.size();i++){
        if(nums[i]==a){
            count++;
        }
        else{
            a=nums[i];
            count=1;
        }
        if(count>2){
            nums.erase(nums.begin()+i);
            k++;
            count--;
            i--;
        }
    }
    return n-k;        
    }
};