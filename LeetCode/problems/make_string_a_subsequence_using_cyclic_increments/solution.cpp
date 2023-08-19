class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) 
    {
        int a=str1.length(), b=str2.length();
        
        if(a<b)
            return false;
        
        int temp=0, i=0;
        
        for(i; i<a && temp<b; i++)
            if((((str1[i]-'a')+1)%26 + 'a' == str2[temp]) or str1[i]==str2[temp])
                temp++;

        if(temp==b)
            return true;
        
        return false;
    }
};