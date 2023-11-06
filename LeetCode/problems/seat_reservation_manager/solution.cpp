class SeatManager {
public:
    
    priority_queue<int, vector<int>, greater<int>> available;
    
    SeatManager(int n) 
    {
        for(int i=1;i<=n;i++)
            available.push(i);
    }
    
    int reserve() 
    {
        int ans=available.top();
        available.pop();
        return ans;
        
    }
    
    void unreserve(int seatNumber) 
    {
        available.push(seatNumber);
        return;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */