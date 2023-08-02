class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int temp1=INT_MIN, temp2=INT_MIN;
        int cnt1=0, cnt2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(cnt1==0 and temp2!=nums[i])
                temp1=nums[i], cnt1+=1;
            
            else if(cnt2==0 and temp1!=nums[i])
                temp2=nums[i], cnt2+=1;
            
            else if(temp1==nums[i])
                cnt1+=1;
            
            else if(temp2==nums[i])
                cnt2+=1;
            
            else
                cnt1-=1, cnt2-=1;            
        }
        
        vector<int> ans;
        cnt1=0, cnt2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(temp1==nums[i]) cnt1+=1;
            if(temp2==nums[i]) cnt2+=1;
        }
        
        int check = (int)nums.size()/3;
        
        if(cnt1>check) ans.push_back(temp1);
        if(cnt2>check) ans.push_back(temp2);
        
        return ans;
    }
};