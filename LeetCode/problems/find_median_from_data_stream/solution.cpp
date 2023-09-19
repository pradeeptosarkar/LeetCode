class MedianFinder {
public:
    
    priority_queue<int> a,b;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        a.push(num);
        b.push(-a.top());
        a.pop();
        
        if(a.size()<b.size())
        {
            a.push(-b.top());
            b.pop();
        }
    }
    
    double findMedian() 
    {
        return a.size()>b.size() ? a.top() : (a.top()-b.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */