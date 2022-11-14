class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        queue<int> que; 
        int size=stones.size(),res=0,count;
        vector<int> v(size,1),counts;
        for(int i=0;i<size;i++)
          {
            if(v[i])
            {
              count=0;
              v[i]=0;
              que.push(i);
              while(!que.empty())
              {
                  int j=que.front();
                  int x=stones[j][0];
                  int y=stones[j][1];
                  for(int k=0;k<size;k++) 
                      if(v[k]&&(stones[k][0]==x||stones[k][1]==y)) 
                          v[k]=0,que.push(k);
                  que.pop();
                  count++;
              }
              counts.push_back(count);
            }     
          }
        for(auto i:counts)res+=i-1;
        return res;     
    }
};