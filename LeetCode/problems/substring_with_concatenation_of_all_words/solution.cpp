class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> result_indices={};
        unordered_map<string, int> count;
        
        for(auto i:words)
            count[i]++;
        
        int l=s.length(), n=words.size(), k=words[0].size();
        
        if(l==0 or n==0)
            return result_indices;
        
        for(int i=0;i<=(l-n*k);i++)
        {
            unordered_map<string,int> visited;
            
            int j=0;
            
            for(;j<n;j++)
            {
                string word= s.substr(i+j*k, k);
                
                if(count.find(word)!=count.end())
                {
                    visited[word]++;
                    
                    if(visited[word]>count[word])
                        break;
                }
                
                else
                    break;
            }
            if(j==n)
                result_indices.push_back(i);
        }
        return result_indices;
    }
};