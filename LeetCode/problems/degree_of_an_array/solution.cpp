class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int,int>mp; //store the frequency of each element present in the array
        int temp=0,n=nums.size();
        for(auto &i:nums){
            mp[i]++;
            if(mp[i]>temp) 
                temp=mp[i]; //find max occurnace element in array
        }
        if(temp==1)
            return 1;
        int ans=INT_MAX;
        for(auto &i:mp){
            if(i.second == temp){ //iterating over all the elments having max occurance
                int l=0,r=n-1;
                while(l<=r && nums[l]!=i.first) //finding left most occurance of that element
                    l++;
                while(l<=r && nums[r]!=i.first) //finding right most occurance of that element
                    r--;
                ans=min(ans,r-l+1);//storing min length subarray->of all the element with max occurance            
            }
        }        
        return ans; //returning min length subarray
    }
};