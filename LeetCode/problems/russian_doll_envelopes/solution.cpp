class Solution {
public:
    
    static bool comp(vector<int>& a, vector<int>& b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        else
            return a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int n=envelopes.size();
        
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> lis;
        
        for(auto i:envelopes)
        {
            int ele=i[1];
            int idx=lower_bound(lis.begin(), lis.end(), ele)-lis.begin();
            
            if(idx>=lis.size())
                lis.emplace_back(ele);
            
            else
                lis[idx]=ele;
        }
        
        return lis.size();
        
    }
};