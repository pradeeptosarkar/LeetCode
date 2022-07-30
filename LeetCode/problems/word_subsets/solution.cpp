class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<string> ans;
        vector<int> max_freq(26,0);
        
        for(auto i:words2)
        {
            vector<int>temp_freq(26,0);
            for(auto j:i)
                temp_freq[j-'a']++;
            for(char k='a';k<='z';k++)
                max_freq[k-'a']=max(temp_freq[k-'a'], max_freq[k-'a']);
        }
        
        for(auto i:words1)
        {
            bool flag=1;
            vector<int> temp(26,0);
            for(auto j:i)
                temp[j-'a']++;
            for(char k='a';k<='z';k++)
                if(temp[k-'a']<max_freq[k-'a'])
                {
                    flag=0;
                    break;
                }
            if(flag)
                ans.push_back(i);
        }
        return ans;
        
    }
};