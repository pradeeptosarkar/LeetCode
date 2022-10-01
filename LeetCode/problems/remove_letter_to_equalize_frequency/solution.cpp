class Solution {
public:
    
    int temp;
    
    bool check(vector<int> a)
    {
        int i;
    
        for (i=0; i<26; i++) 
        {
            if (a[i] > 0) 
            {
                temp=a[i];
                break;
            }
        }
    
        for (int j=i+1;j<26;j++)
            if (a[j]>0 && a[j]!=temp)  
                return false;
        
        return true;
    }
    
    bool equalFrequency(string word) 
    {
        
        vector<int> a(26,0);
        
            for (auto i: word)        
                a[i-'a']++;

    
        if(check(a) and temp==1)
            return true;
 
        char c='a';
        
        while(c<='z')
        {
            int i=c-'a';
 
            if (a[i] > 0) 
            {
                a[i]--;
                if(check(a))
                    return true;
                
                a[i]++;
            }
            c++;
        }
        
        return false;
  
    }
};