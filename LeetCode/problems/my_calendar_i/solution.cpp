class MyCalendar {
public:
    map<int,int> schedule;
    
    MyCalendar() 
    {
        
    }
    
    bool book(int start, int end) 
    {
        auto lower=schedule.lower_bound(start);
        if(lower==schedule.end() or lower->second>=end)
        {
            schedule[end-1]=start;
            return true;
        }
        return false;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */