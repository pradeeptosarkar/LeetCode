

      




class NumArray {
public:
    vector<int> arr;
    int prev=0;
    NumArray(vector<int>& nums) {
        arr=nums;
        for(int i=0;i<nums.size();i++)
        {
            prev+=nums[i];
        }
    }
    
    void update(int index, int val) {
        prev=prev-arr[index];
        arr[index]=val;
        prev+=val;
        
    }
    
    int sumRange(int left, int right) {
        int tl=prev;
         for(int i=0;i<left;i++)
             tl-=arr[i];
          for(int i=right+1;i<arr.size();i++)
             tl-=arr[i];
        return tl;
    }
};


    
