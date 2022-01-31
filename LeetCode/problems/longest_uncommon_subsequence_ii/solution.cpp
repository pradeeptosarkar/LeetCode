class Solution {
public:
    
    bool isSubsequence(string s1, string s2)
    {
        int i=0,j=0;
        while(i<s1.size() && j<s2.size())
        {
            if(s1[i]==s2[j])
                i++;
            j++;
        }
        return i==s1.size();
    }
    
    int findLUSlength(vector<string>& strs) 
    {
        sort(strs.begin(), strs.end(), [](string& a, string& b){return a.size()>b.size();});
        
        for(int i=0;i<strs.size();i++)
        {
            cout<<strs[i]<<endl;
            bool flag=false;
            
            for(int j=0;j<strs.size();j++)
            {
                if(i!=j && isSubsequence(strs[i],strs[j]))
                {
                    flag=true;
                    break;
                }
            }
            if(flag==false)
                return strs[i].size();
        }
        
        return -1;
    }
};