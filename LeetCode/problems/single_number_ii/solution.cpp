class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        map<int,int> count;
        
        for(int i:nums)
            count[i]++;
        
        for(int i:nums){
            if(count[i]==1)
                return i;}
        return -1;
    }
};