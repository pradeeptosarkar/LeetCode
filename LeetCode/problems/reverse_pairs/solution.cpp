class Solution {
public:
    int merge_sort(int l, int mid, int r,vector<int>& a)
    {
        int lz = mid - l + 1;
        int rz = r - (mid+1) +1;
        long left[lz];
        long right[rz];
        int ind = l;
        
        for(int i = 0 ;i<lz;i++)
            left[i] = a[l+i];
        
        for(int i = 0 ;i<rz;i++)
            right[i] = a[(mid+1)+i];
        
        int i = 0;
        int j = 0;
        int inversion = 0;
        
        while(i<lz && j<rz)
        {
            while(i<lz && left[i]<=(long) 2*right[j])
                i++;
            
            inversion+= lz - i;
            j++;
        }
        i = 0;
        j = 0;
        
        while(i<lz && j<rz)
        {
            if(left[i]<=right[j]){
                a[ind] = left[i];
                i++;
                ind++;
            }
            else{
                a[ind] = right[j];
                j++;
                ind++;
            }
        }
        while(i<lz)
        {
            a[ind] = left[i];
            i++;
            ind++;
        }
        while(j<rz)
        {
            a[ind] = right[j];
            j++;
            ind++;
        }
        sort(a.begin()+l,a.begin()+r);
        return inversion;
        
    }
    
    int merge(int l,int r,vector<int>& nums)
    {
        if(l==r)
            return 0;
        
        int inversion = 0;
        int mid = (l+r)/2;
        inversion+=merge(l,mid,nums);
        inversion+=merge(mid+1,r,nums);
        inversion+=merge_sort(l,mid,r,nums);
        
        return inversion;
    }
    
    int reversePairs(vector<int>& nums) 
    {
        if(nums.size()==0 || nums.size()==1)
            return 0;
        
        return merge(0,nums.size()-1,nums);
    }
};