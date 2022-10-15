class Solution {
public:
    int compress(vector<char>& chars) 
    {
        string s;
        int c=1,i;
        for(i=1;i<chars.size();i++)
        {
            if(chars[i]==chars[i-1])
                c++;
            
            else if(chars[i]!=chars[i-1] && c==1)
                s+=chars[i-1];
            
            else
            {
                s+=chars[i-1];
                s+=to_string(c);
                c=1;
            }
        }
        
        if(c==1)
            s+=chars[i-1];
        
        else
            s+=chars[i-1]+to_string(c);
        
        for(int i=0;i<s.length();i++)
            chars[i]=s[i];
        
        
        vector<char>::iterator it;
        vector<char>::iterator ty;
        it=chars.begin()+s.length();
        ty=chars.begin()+chars.size();
        chars.erase(it,ty);
        return s.length();
    }
};