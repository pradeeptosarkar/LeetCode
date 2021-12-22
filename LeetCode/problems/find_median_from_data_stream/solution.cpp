class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top()>num){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        
        int maxLen = maxHeap.size();
        int minLen = minHeap.size();
        if(maxLen+1 > minLen){
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
        if(maxLen < minLen+1){
            int top = minHeap.top(); minHeap.pop();
            maxHeap.push(top);
        }
      
    }
    
    double findMedian() {
        int maxLen = maxHeap.size();
        int minLen = minHeap.size(); 
        
        if(minLen == maxLen){
          return minLen==0?0:(maxHeap.top() + minHeap.top())/2.0;
        }
 
        return (maxLen > minLen)?maxHeap.top():minHeap.top();
        
    }
};