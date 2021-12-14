class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int max=INT_MIN,ans=-1;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            ans=i;
        }
    }
    return ans;
    }
};