class MedianFinder {
    
private:
    priority_queue<int> a;
    priority_queue<int> b;
    
public:
    MedianFinder() { }
    
    void addNum(int num) 
    {
        a.push(-num);
        b.push(-a.top());
        a.pop();
        
        if(b.size()>a.size())
            a.push(-b.top()), b.pop();
    }
    
    double findMedian() 
    {
        if(a.size()==b.size())
            return(b.top()-a.top())/2.00;
        return -a.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */