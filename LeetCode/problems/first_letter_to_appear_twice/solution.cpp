class Solution {
public:
    char repeatedCharacter(string s) 
    {
        unordered_set<char>sett;
        char ans;
        for(auto i:s)
        {
            if(sett.find(i)==sett.end())
                sett.insert(i);
            else 
            {ans=i; break;}
        }
        return ans;
    }
};