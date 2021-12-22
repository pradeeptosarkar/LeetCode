class Solution {
public:
  int countConsistentStrings(string allowed, vector<string>& words)
  {
    int len = allowed.length(), f=0, ans=0;
    for(int i=0;i<len;i++)
    {
      f = f|(1<<(allowed[i]-'a'));
    }
    int n = words.size();
    for(int i=0;i<n;i++)
    {
      int word_len = words[i].length(), temp=0;
      for(int j=0;j<word_len;j++)
      {
        if((f&(1<<(words[i][j]-'a'))) == 0) continue;
          temp+=1;
      }
      if(temp==word_len) ans += 1;
    }
    return ans;
  }
};