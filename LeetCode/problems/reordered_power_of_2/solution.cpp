class Solution {
public:
    
    string sort_ascending(long long int n)
    {
        string temp=to_string(n);
        sort(temp.begin(), temp.end());
        return temp;
    }
    
    bool reorderedPowerOf2(int n) 
    {
        long long temp=1;
        vector<string> a(30);
        a[0]="1";
        
        for(int i=1;i<=29;i++)
        {
            temp*=2;
            a[i]=sort_ascending(temp);
        }
        
        string s=sort_ascending(n);
        
        if(find(a.begin(), a.end(), s)!=a.end())
            return 1;
        else
            return 0;
        
    }
};