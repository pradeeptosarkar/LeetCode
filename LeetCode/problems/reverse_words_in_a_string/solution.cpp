class Solution {
public:
    string reverseWords(string s) 
    {
        string ans="";
        string word = "";
        
        for (auto x : s)
        {
            if (x == ' ')
            {
                if(word!="")
                {
                    if(ans=="")
                        ans=word;
                    
                     else
                        ans=word+" "+ ans;                
                }
                word = "";
            }
            else 
                word = word + x;
            
        }
            if(word!="")
            {
                    if(ans=="")
                        ans=word;
                    else
                        ans=word+" "+ ans;
                    
            }
         return ans;
    }
};