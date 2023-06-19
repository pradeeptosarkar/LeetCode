class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int ans=gain[0];
        int temp=gain[0];
        if(gain.size()==1)
            return (ans>=0)?ans:0;
        
        for(int i=1;i<gain.size();i++)
        {
            temp+=gain[i];
            ans=max(ans,temp);
        }
        return (ans>=0)?ans:0;
    }
};