bool f( pair<int,string> a,pair<int,string> b){
    
    if(a.first==b.first) return a.second<b.second;
    
    return a.first>b.first;
    
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
         vector<string>  res;
        map<string,int> freq;
        for(int i=0;i<n;i++) 
            freq[words[i]]++;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(&f) > pq(f);
        
        for(auto i:freq){
            
            pq.push({i.second,i.first});
            if(pq.size()>k) pq.pop();
         }
        
        while(pq.empty()==0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
      
        
         return res;
    }
};