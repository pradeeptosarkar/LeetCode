class Solution {
public:
    
    vector<string> nums={"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};
    
    bool containsString(string num, string numsi)
    {
        for(int i=0;i<num.size()-2;i++)
            if(num[i]==numsi[0] and num[i+1]==numsi[1] and num[i+2]==numsi[2])
                return true;
            
            return false;
    }
    
    string largestGoodInteger(string num) 
    {
        for(auto numsi:nums)
            if(containsString(num,numsi))
                return numsi;
        
        return "";        
    }
};