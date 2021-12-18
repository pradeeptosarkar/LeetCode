class Solution {
public:
    string addStrings(string a, string b) {
         if(a.size() < b.size())
        swap(a,b) ; 
    
    
     int n = a.size() ; 
    int  m = b.size() ; 
    int  i= n-1 , j=m-1 ; 
    int carry = 0 ; 
    string ans =""; 
    while(i>=0 and j>=0  )
    {
        int d1 = a[i]-'0'; 
        int d2 = b[j]-'0'; 
        int sum = d1+d2+ carry ; 
        carry = sum/10 ; 
        int d3= sum%10 ; 
        char c= d3+'0'; 
        ans+=c ; 
        i-- ; 
        j-- ; 
    }
    while(i>=0 )
    {
        int d1 = a[i]-'0';
        int sum = d1+ carry ; 
        carry = sum/10 ; 
        int d3= sum%10 ; 
        char c= d3+'0'; 
        ans+=c ; 
        i-- ; 
    }
    if(carry> 0 )
    {
        char c= carry+'0'; 
        ans.push_back(c) ; 
    }
    reverse(ans.begin(), ans.end()) ; 
    return ans ;
    }
};