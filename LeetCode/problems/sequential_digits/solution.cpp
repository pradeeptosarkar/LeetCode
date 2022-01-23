class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int num=0;
        
        for(int i=1;i<=9;i++)
        {
            num=i;
            
            for(int j=i+1;j<=9;j++)
            {
                num*=10;
                num+=j;
                
                if(num>=low && num<=high)
                    ans.push_back(num);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};