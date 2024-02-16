class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        unordered_map<int,int> mp;
        
        for(int i:arr)
            mp[i]++;
        
        int n=arr.size();
        vector<int> countFreq(n+1,0);
        
        for(auto i:mp)
            countFreq[i.second]++;
        
        int remainingElem=mp.size();
        
        for(int i=1;i<=n;i++)
        {
            int removeElem = min(k/i, countFreq[i]);
            
            k-=(removeElem*i);
            
            remainingElem-=removeElem;
            
            if(k<i)
                return remainingElem;
        }
        
        return 0;
    }
};