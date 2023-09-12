class Solution {
public:
    string getPermutation(int n, int k) 
    {
        string ans="";
        int fact=1;
        vector<int> arr;
        
        for(int i=1; i<=n;i++)
        {
            fact*=i;
            arr.push_back(i);
        }
        
        fact/=arr.size();
        k-=1;
        
        while(true)
        {
            ans+=to_string(arr[k/fact]);
            arr.erase(arr.begin() + k/fact);
            
            if(!arr.size())
                break;
            k%=fact;
            fact/=arr.size();
        }
        
        return ans;
    }
};