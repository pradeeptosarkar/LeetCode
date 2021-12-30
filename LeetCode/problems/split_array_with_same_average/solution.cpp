class Solution {
public:
    
    bool splitArraySameAverage(vector<int>& nums) {
        
        int totalSum = 0; for(int n : nums) totalSum += n;
        vector<int> masks; int n = nums.size();
        
        if (!necessaryCond(totalSum, n))
            return false;

        // for the cases with repeating nubers ([60,30,30,30,...])
        // The shifts are used instead of calling function pow(2, n-1)
        for(int i = 0; i < n - 1; ++i) 
            if(nums[i] == nums[i + 1]) 
                masks.push_back(1 << (n - i - 1));
            
        // 1 goes from 1 to 2^n-1 because we divide the 2^n possibilities by 2 
        // to avoid to compute the same partitions twice
        for(int i = 1; i < (1 << n - 1); ++i) {
            int sum = 0; int nbItem = 0;
            for(int mask = (1 << n - 1), j = 0; mask > 0; mask >>= 1, j++) 
                if(mask & i) {sum += nums[j]; nbItem++;}
               
            // i jumps immediately if we reach consecutive equal numbers. For example,
            // [2,2,2,4,5] is masked with 1,2,3,4,5,6,7 and next 13 because we don't 
            // want to test multiple times the same sub arrays [2], [2,2],..
            if(!masks.empty() && i >= masks.back()) {i += masks.back(); masks.pop_back();}
            
            // more performant than division
            if(sum * n == nbItem * totalSum)
                return true;
        }
        return false;
    }
    
    // sum/n = sum1/n1 <=> n must divide n1 * sum
    bool necessaryCond(int sum, int n) {
        for (int i = 1; i < n; ++i)
            if (i * sum % n == 0)
                return true;
            return false;
    }
};