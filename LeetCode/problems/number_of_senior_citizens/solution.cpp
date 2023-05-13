class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int ans=0;
        
        for(auto i:details)
            if((i[11]-48)*10+(i[12]-48)>60)
                ans++;
        return ans;
        
    }
};