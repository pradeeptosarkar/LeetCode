class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), greater<int>());
        deque<int> dq;
        
        for(int i=0;i<nums.size();i++)
        {
            if(dq.front()==nums[i])
                continue;
            dq.push_front(nums[i]);
            
            if(dq.size()==3){return dq.front();}
        }
        return dq.back();
        
    }
};