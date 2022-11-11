class Solution {
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int ans=0;
        
        for(int i=0;i<sentences.size();i++)
        {
            string temp=sentences[i];
            int tempAns=0;
            for(int j=0;j<temp.length();j++)
                if(temp[j]==' ')
                    tempAns++;
            ans=max(ans,tempAns);
        }
        return ++ans;
    }
};