class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int ans=0, total=0, temp=0;
        
        for(int i=0;i<gas.size();i++)
        {
            total+=gas[i]-cost[i];
            temp+=gas[i]-cost[i];
            
            if(temp<0)
                temp=0, ans=i+1;
        }
        return (total<0)?-1:ans;
        
    }
};