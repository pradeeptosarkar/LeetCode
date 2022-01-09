class Solution {

public:
    int countArrangement(int n) {  
	// use it to track the used number in one permutation
      vector<int> visited(n+1);
	  // set start depth to 1, easier to match the number from 1 ~N
      dfs(n, 1, visited, true);
      return ans;
    }
    
private: 
    int ans = 0;
void dfs(int n, int depth, vector<int>& visited, bool flag) {
//if we also detect one false element, we can prune the branch in advance.
    if(!flag) {
        return;
    }
	// if we have moved n steps and all elements has passed the codnition, we get one passed permutation.
    if(depth == n+1 && flag) {
        ans ++;
    }
    for(int i = 1; i<= n; i ++) {
	   // if the number has been used, skip it.
        if(visited[i] == 1)
            continue;
			//mark it to used and calculate the condition
			// to reset the condition when we are back, use third variable to track it. 
			// then when we get back, we don't need to reset the flag. 
        visited[i] = 1;
        bool next_flag = flag && (depth % i == 0 || i % depth == 0);
        dfs(n, depth+1, visited, next_flag);
		// still need to reset the tracking vector. 
        visited[i] = 0;  
    }   
}
};