class Solution {
public:
   
    vector<int> maxSubsequence(vector<int>& a, int k) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // {element,idx}
    
    int n=a.size();
    for(int i=0;i<n;i++){
        if(pq.size()<k){
            pq.push({a[i],i});
        }else if(pq.size()==k && pq.top().first<a[i]){
            pq.pop();
            pq.push({a[i],i});
        }
    }
    
    vector<pair<int,int>> sub;
    while(pq.size()>0){
        int val=pq.top().first, idx=pq.top().second;
        pq.pop();
        
        sub.push_back({idx,val});
    }
    sort(sub.begin(),sub.end());
    
    vector<int> ans;
    for(int i=0;i<k;i++) ans.push_back(sub[i].second);
    
    return ans;
    }
};