/* class Solution {
public:
    string removeKdigits(string num, int k) {
        
    }
};*/
    
    class Solution {

public:

string removeKdigits(string num, int k) {

string S="";

int n=num.length();

    S.push_back(num[0]);

    for(int i=1; i<n; i++)

    {

        while(k && S.back()>num[i])

        {

            k--;

            S.pop_back();

        }

        S.push_back(num[i]);

    }

    while(k && !S.empty())

    {

        k--;

        S.pop_back();

    }

    

    if(S.length()>1 && S[0]=='0')

    {

        reverse(S.begin(),S.end());

        while(S.back()=='0') S.pop_back();

        reverse(S.begin(),S.end());

    }

    

   return S==""?"0":S;

}

};