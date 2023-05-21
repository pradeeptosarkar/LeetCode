class Solution {
    public:
    int punishmentNumber(int n) 
    {        
        int ans = 0;
        for (int i = 1; i <= n; i++) 
            if (check(i)) 
                ans += i * i;            
        
        return ans;
    }
    
    bool check(int i) 
    {
        int sq= i*i;        
        std::string temp = std::to_string(sq);
        return dfs(temp, 0, i);    
    }
    
    bool dfs(string& temp, int index, int t) 
    {
        if (t == 0 && index == temp.length()) 
            return true;
        
        if (t < 0 || index == temp.length()) 
            return false;        
        
        for (int i = index + 1; i <= temp.length(); i++) 
        {
            int num=stoi(temp.substr(index, i-index));
            
            if (dfs(temp,i,t-num))   
                return true;
        }
        return false;    
    }
};