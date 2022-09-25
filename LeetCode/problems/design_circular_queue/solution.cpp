class MyCircularQueue {
private:
    int *nums;
    int capacity;
    int size;
    int front;
    int rear;
    
public:
    MyCircularQueue(int k) 
    {
        nums = (int *)malloc(sizeof(int) * k);
        capacity = k;
        size = 0;
        front = 0;
        rear = -1;
    }
    
    bool enQueue(int value) 
    {
        if (size == capacity) 
            return false;
        rear = (rear + 1) % capacity;
        nums[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() 
    {
        if (size == 0) 
            return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() 
    {
        return size == 0 ? -1 : nums[front];
    }
    
    int Rear() 
    {
        return size == 0 ? -1 : nums[rear];
    }
    
    bool isEmpty() 
    {
        return size == 0;
    }
    
    bool isFull() 
    {
        return size == capacity;
    }
};