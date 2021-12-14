class Solution 
{
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        map<int,int> count;
        int sum=0;
        for(auto i:nums)
        {
            count[i]++;
        }
        for(auto i=count.begin();i!=count.end();i++)
        {
            if(i->second>1)
                sum+= i->second*(i->second-1)/2;
        }
        return sum;
    }
};