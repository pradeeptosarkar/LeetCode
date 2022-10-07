class MyCalendarThree {
public:
  map<int,int> mp;
  int ans=0;
    
  MyCalendarThree()
  {
      
  }

  int book(int start, int end)
  {
    mp[start]++;
    mp[end]--;
    int temp=0;
    for (auto it:mp)
    {
      temp+=it.second;
      ans=max(ans, temp);
    }
    return ans;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */