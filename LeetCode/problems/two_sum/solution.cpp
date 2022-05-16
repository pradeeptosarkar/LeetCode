class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> a=nums;  
		int start=0, end=nums.size()-1, sum;  
        sort(a.begin(), a.end());  
        while(start<end){
            sum=a[end]+a[start];
            if(sum==target)
            {
                int x=-1, y=-1;
                for(int i=0; i<nums.size(); i++)
                {
                    if(x!=-1 and (nums[i]==a[end] or nums[i]==a[start]))
                        y = i;
                    else if(x==-1 and (nums[i]==a[start] or nums[i]==a[end]))
                        x = i;
                    if(y>0)
                        return {x,y};
                }
            }
            else if(sum<target)
                start++;
            else
                end--;
        }
        return {-1,1};
    }
};