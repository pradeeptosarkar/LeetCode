class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) 
    {
        if(suits[0]==suits[1] and suits[1]==suits[2] and suits[2]==suits[3] and suits[3]==suits[4])
            return "Flush";
        
        bool ans=false;
        
        unordered_map<int,int>mp;
            for(int i: ranks)
                mp[i]++;
            
            for(auto i:mp)
            {
                if(i.second>=3)
                    return "Three of a Kind";
                else if(i.second==2)
                    ans=true;
            }
        
        
        if(ans==true)
            return "Pair";
        
        return "High Card";
        
    }
};