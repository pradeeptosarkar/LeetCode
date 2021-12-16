class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        for(int i=0;i<numbers.size();i++)
        {
            int lb=0,ub=numbers.size()-1,mid=0;
            while(lb<=ub)
            {
                mid=lb+(ub-lb)/2;
                if(numbers[i]+numbers[mid]==target)
                {
                    if(mid==i)
                    {
                        if(numbers[i]+numbers[mid+1]==target)
                            mid++;
                        else if(numbers[i]+numbers[mid-1]==target)
                            mid--;
                    }
                    return vector<int>{i+1,mid+1};
                }
                    
                else if(numbers[i]+numbers[mid]<target)
                    lb=mid+1;
                else
                    ub=mid-1;
            }
            
        }
        return vector<int>{0,0};
    }
};