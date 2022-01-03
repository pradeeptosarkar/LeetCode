class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
    //if we have already visited that value , we return false
        if(arr[start]== -1) return false;
        //best case scenerio will be if arr[start] is 0 so we return true
        if(!arr[start]) return true;
        //For leftside and rightside jumps       
        int leftside= start-arr[start] ,rightside = start+arr[start];
        //since we start from arr[start] it should be marked as visited
        arr[start] = -1;
        
        //Now the scenerio were arr[start] != 0 then we need to check if we can either jump to leftside or rightside i.e recursively 
        return rightside = (rightside < arr.size() && canReach(arr,rightside) ) || (leftside>=0 && canReach(arr,leftside) );
    
    }
};