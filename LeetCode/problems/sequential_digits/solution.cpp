class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int> ans;
        string s="123456789";
        
        for(int len=2;len<=s.length();len++)
        {
            for(int idx=0;idx<=s.length()-len;idx++)
            {
                string temp=s.substr(idx, len);
                int tempString=stoi(temp);
                
                if(tempString>=low and tempString<=high)
                    ans.push_back(tempString);
            }
        }
        
        return ans;
    }
};