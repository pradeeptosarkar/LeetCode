class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        for(int i=words.size()-1;i>0;i--)
        {
            string temp2=words[i];
            string temp1=words[i-1];
            sort(temp1.begin(),temp1.end());
            sort(temp2.begin(),temp2.end());
            if(temp1==temp2)
                words.erase(words.begin()+i);
        }
        return words;
        
    }
};