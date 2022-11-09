class StockSpanner {
 public:
  stack<int> s;
  vector<int> A;
  int index;
	
StockSpanner() {
    index=1;    
    s.push(-1);
}

int next(int price) {
    int cnt;
    
    while(s.top()!=-1 && A[s.top()] <= price) {
        s.pop();
    }
    
    cnt = A.size() - s.top();
    
    s.push(A.size());
    A.push_back(price);
    
    return cnt;
}
};