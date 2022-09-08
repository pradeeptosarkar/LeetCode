class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) 
    {
        for(int i=0;i<s.size();i++)
        {
            int temp=distance[s[i]-'a'];
            
            if(i+temp+1>=s.size() or s[i+temp+1]!=s[i])
                return false;
            
            distance[s[i]-'a']=-1;
        }
        return true;
        
    }
};