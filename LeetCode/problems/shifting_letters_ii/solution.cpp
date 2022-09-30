class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        
        int size=s.size();
        vector<int> vec(size+1);
    
        for(auto it:shifts)
        {
        int start=it[0],end=it[1],dir=it[2];
        
        if(dir==1)
        {
            vec[start]+=1;
            vec[end+1]+=-1;
        }
            
        else
        {
            vec[start]+=-1;
            vec[end+1]+=1;
        }
    }
    int prefixSum=0;
    
    for(int i=0;i<size;i++)
    {
        prefixSum+=vec[i];
        while(prefixSum<0)
            prefixSum+=26;
        s[i]=(char)('a'+(((s[i]-'a')+prefixSum)%26));
    }   
        
    return s;
    }
};