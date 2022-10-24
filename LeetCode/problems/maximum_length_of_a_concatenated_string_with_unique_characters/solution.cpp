class Solution {
public:
    
    bool checkUnique(string s)
    {
        if(s.length()>26)
            return false;
        
        set<int> st;
        
        for(auto i:s)
        {
            if(st.find(i)!=st.end())
                return false;
            else
                st.insert(i);
        }
        return true;
    }
    
    int maxLength(vector<string>& arr) 
    {
        int ans=0;
        vector<string> ansVec;
        ansVec.push_back("");
        
        for(auto i:arr)
        {
            if(!checkUnique(i))
                continue;
            
            vector<string> tempVec;
            string tempString;
            
            for(auto temp:ansVec)
            {
                tempString=temp+i;
                
                if(checkUnique(tempString))
                {
                    tempVec.push_back(tempString);
                    if(tempString.size()>ans)
                        ans=tempString.size();
                }
            }
            ansVec.insert(ansVec.end(), tempVec.begin(), tempVec.end());
        }
        return ans;
        
    }
};