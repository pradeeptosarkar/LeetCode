class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
         vector<pair<char,int>>table;
    int answer = 0;
    
    for(int i = 0; i != s.size();){
      table.push_back({s[i], 1});
      while(++i != s.size() && table.back().first == s[i]) table.back().second++;
    }
    
    for(auto &w: words){
      int j = 0, i = 0;
      
      for(int count = 1 ; i != w.size() && j != table.size() && w[i] == table[j].first; j++, count = 1){
        while(++i != w.size() && w[i] == table[j].first) count++;
        if(table[j].second != count && (table[j].second < 3 || table[j].second < count)) break;
      } 
      
      if(j == table.size() && i == w.size()) answer++;
    }
    
    return answer;
    }
};