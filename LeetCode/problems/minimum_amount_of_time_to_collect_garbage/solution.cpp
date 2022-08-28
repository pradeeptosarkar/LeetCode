class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        int m=0,p=0,g=0;
        int mm=-1,pm=-1,gm=-1;
        
        for(int i=0;i<garbage.size();i++)
        {
            string sr=garbage[i];
            for(int j=0;j<sr.size();j++)
            {
                if(sr[j]=='M')
                    m++, mm=i;
                else if(sr[j]=='P')
                    p++, pm=i;
                else
                    g++, gm=i;
            }
        }
        
        
        for(int i=0;i<travel.size();i++)
        {
            if(i<mm) m+=travel[i];
            if(i<pm) p+=travel[i];
            if(i<gm) g+=travel[i];
        }
        
        return m+p+g;
    }
};