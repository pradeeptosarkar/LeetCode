class Solution {
public:
    vector<int> constructArray(int n, int k) {
        
        vector<int>res(n,0);
        
        int left=1,right=n,i=0;
        
        while(i<n-k)
            res[i++]=left++;
      
        while(i<n){
            
            res[i++]=right--;
            
            if(i==n)break;
            
            res[i++]=left++;
            
        }
        return res;
    }
};