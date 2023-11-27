class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        vector<int> prefixSum(travel.size()+1, 0);
        prefixSum[1]=travel[0];
        
        for(int i=1;i<travel.size();i++)
            prefixSum[i+1]=prefixSum[i]+travel[i];
        
        unordered_map<char,int> lastPos;
        unordered_map<char,int> count;
        
        for(int i=0;i<garbage.size();i++)
        {
            for(int j=0;j<garbage[i].size();j++)
            {
                lastPos[garbage[i][j]]=i;
                count[garbage[i][j]]+=1;
            }
        }
        
        vector<char> types = {'M', 'P', 'G'};
        int ans=0;
        
        for(auto c:types)
            if(count[c])
                ans+=count[c]+prefixSum[lastPos[c]];
        
        return ans;
    }
};