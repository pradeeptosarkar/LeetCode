class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quant) {
        int m=quant.size();
		
		// Sort the given array to access maximum element.
        sort(quant.begin(),quant.end());
        int max=quant[m-1];
        
		// Apply binary search from 1 to max element so, we can find the given even distribution for the retail stores.
		int start=1;
        int end=max;
        while(start<end){
            int mid=(start+end)/2;
            int cntr=0;
            for(int i=0;i<m;i++)
                cntr+=quant[i]/mid+(quant[i]%mid!=0); // Calculate the distributions made by each and every binary search value
            if(cntr<=n){
                end=mid;
            }else{
                start=mid+1;
            }
        }
        return start;
    }
};