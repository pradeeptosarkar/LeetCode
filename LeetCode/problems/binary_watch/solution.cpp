class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
      vector<string> ans;
      for(int hour=0;hour<12;hour++)
      {
          for(int minutes=0;minutes<60;minutes++)
          {
              bitset<4> b1(hour);
              bitset<6> b2(minutes);
              if(b1.count()+b2.count()==turnedOn)
              {
                  string res="";
                  res+=to_string(hour);
                  res+=':';
                  if(minutes<10)
                  {
                      res+='0';
                      res+=to_string(minutes);
                  }
                  else
                  {
                      res+=to_string(minutes);
                  }
                  ans.push_back(res);
              }
          }
      }
    return ans;
    }
};