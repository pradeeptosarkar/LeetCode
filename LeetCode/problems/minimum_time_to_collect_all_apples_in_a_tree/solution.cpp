class Solution {
public:

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        vector<int> temp(n,INT_MAX);

        for (auto &i:edges) 
        {
            temp[i[0]]=min(i[1], temp[i[0]]);
            temp[i[1]]=min(i[0], temp[i[1]]);

        }

        vector<bool> toVisit(n,false);

        int j=0;
        for (int i=n-1;i>0;--i) 
        {
            if(hasApple[i]){
                j = i;
                while(not toVisit[j] && j!=0)
                {
                    toVisit[j]=true;
                    j=temp[j];
                }
            }
        }

        int ans=0;
        
        for (auto i:toVisit) 
            ans+=int(i);
        
        return  ans*2;
    }
};