class MyCalendarTwo {
public:
    
    set<pair<int,int>> list1;
    set<pair<int,int>> list2;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) 
    {
        auto i2 = list2.lower_bound(pair<int,int>(start,start));
        if(i2!=list2.end() and i2->second<end)
            return false;         
        
        auto i1 = list1.lower_bound(pair<int,int>(start,start));
        while(i1!=list1.end())
        {
            int s=i1->second;
            int e=i1->first;
            
            if(end<s)
                break;
            
            else if(end==s)
            {i1=list1.erase(i1); end=e;}
            
            else
            {
                list2.insert(pair<int,int>(min(e,end), max(s,start)));
                start=min(s,start);
                end=max(e,end);
                i1=list1.erase(i1);
                
            }
        }
        list1.insert(pair<int,int>(end,start));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */