class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i,n,pos,c1=0,c2=0;
        n=arr.size();
        for(i=0;i<n-1;i++)
        {
            if(arr[i]<arr[i+1])
                c1++;
            if(arr[i]>arr[i+1])
                break;
        }
        pos=i;
        for(i=pos;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
                c2++;
        }
        if(c1+c2==n-1 && c1>0 && c2>0)
            return true;
        else
            return false;
        
    }
};