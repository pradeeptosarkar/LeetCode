class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) 
    {
        vector<int> ans={};
        
        if(stamp[0]!=target[0] or stamp[stamp.size()-1]!=target[target.size()-1])
            return ans;
        
        if(stamp==target)
            return ans={0};
        
        int s=stamp.size(), t=target.size()-s+1;
        bool tdiff=true, sdiff;
        int i,j;
        
        while(tdiff)
        {
            for(i=0, tdiff=0; i<t; i++)
            {
                for(j=0, sdiff=0; j<s; j++)
                {
                    if(target[i+j]=='*')
                        continue;
                    else if(target[i+j]!=stamp[j])
                        break;
                    else
                        sdiff=true;
                }
                
                if(j==s and sdiff)
                {
                    for(j=i, tdiff=1; j<s+i; j++)
                        target[j]='*';
                    ans.push_back(i);
                }
                    
            }
        }
        for(i=0;i<target.size();i++)
            if(target[i]!='*')
                return {};
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};