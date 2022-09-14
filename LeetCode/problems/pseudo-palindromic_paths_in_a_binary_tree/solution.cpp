class Solution {
public:
    
    vector<int> path;
    int count; 
    int arr[10];
    
    
    void checkPalindrome(){
        
        int c  = 0;
        for(int i=1; i<10; ++i)
            if(arr[i]&1) 
                c++;
        
        
        if(c<=1)
            count++;
        
    }
    
    void dfs(TreeNode* node){
        
        if(!node) return;
        
        if(node->left==NULL && node->right==NULL){
           
            path.emplace_back(node->val); 
            arr[node->val]++; 
			
            checkPalindrome(); 
			
            arr[path.back()]--; 
            path.pop_back(); 
            return;
            
        }
        
        
        path.emplace_back(node->val);
        arr[node->val]++;
        
        
        dfs(node->left);
        dfs(node->right);
        
        
        arr[path.back()]--;
        path.pop_back();
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
    
        count = 0;
        memset(arr, 0, sizeof(arr));
        dfs(root);
        
        return count;
    }
};