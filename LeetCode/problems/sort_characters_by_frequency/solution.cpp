class Solution {
public:
    string frequencySort(string s) 
    {
        map<char,int> count;
        
        for(auto i : s)
            count[i]++;
        
        map<int,string> bucket;
        
        for(auto i = count.begin(); i!=count.end();i++)
            bucket[i->second]+=string(i->second,i->first);
        
        string ans;
        
        for(auto i = bucket.rbegin(); i!=bucket.rend();i++)
            ans+=i->second;
        
        return ans;
    }
};