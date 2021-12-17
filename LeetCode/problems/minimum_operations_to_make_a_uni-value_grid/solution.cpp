class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
       vector<int> output;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            output.push_back(grid[i][j]);
        }
    }
    
	//Sorting the vector
    sort(output.begin(),output.end());
    int n=output.size();
	
	//Finding the midpoint and making all the values equal to the midpoint 
    int mid=output[n/2];
    
    int ans=0;
    for(int i=0;i<n/2;i++){
        ans+=(mid-output[i])/x;
        if(ceil(mid-output[i])/x  != floor((mid-output[i])/x)) return -1;
    }
    for(int i=n/2+1;i<n;i++){
        ans+=(output[i]-mid)/x;
        if(ceil(mid-output[i])/x  != floor((mid-output[i])/x)) return -1;
    }
    return ans; 
    }
};