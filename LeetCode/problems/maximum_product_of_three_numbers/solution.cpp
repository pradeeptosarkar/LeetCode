class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
       int min1, min2, max1, max2, max3;
        int ans2 = 1, ans1 = 1;
        
        //when a priority queue is made directly then make heap func is called having tc of O(n)
        priority_queue<int>quMax(nums.begin(), nums.end());
        //since we are popping out elements from the pq exactly 3 times so this is a O(1) operation
        max1 = quMax.top();quMax.pop();
        max2 = quMax.top();quMax.pop();
        max3 = quMax.top();quMax.pop();
        
        //when a priority queue is made directly then make heap func is called having tc of O(n)
        priority_queue<int, vector<int>, greater<int>>quMin(nums.begin(), nums.end());
        //since we are popping out elements from the pq exactly 2 times so this is a O(1) operation
        min1 = quMin.top(), quMin.pop();
        min2 = quMin.top(), quMin.pop();
        
        ans1*=(min2*min1*max1);
        ans2*=(max1*max2*max3);
        
        return max(ans1, ans2);
    }
};