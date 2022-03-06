//::Pradeepto Sarkar LC976:://

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int perimeter = 0;
        bool flag = false;
        int i = nums.size() - 1;
        while(i >= 2){
            int side1 = nums[i];
            int side2 = nums[i-1];
            int side3 = nums[i-2];
            if(side2 + side3 > side1){
                perimeter = side1 + side2 + side3;
                flag = true;
                break;
            }else{
                i--;
            }
        }
        if(flag)
            return perimeter;
        else
            return 0;
    }
};