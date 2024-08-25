class Solution{
    
    int cnt = 0;
    
    int helper(Node *root, int k){
        if(root == NULL){
            return -1;
        }
        
        int rans = helper(root->right, k);
        if(rans != -1){
            return rans;
        }
        
        cnt++;
        if(cnt == k){
            return root->data;
        }
        
        int lans = helper(root->left, k);
        if(lans != -1){
            return lans;
        }  
        
        return -1;
    }
    
    public:
    int kthLargest(Node *root, int k){
        if(root == NULL){
            return -1;
        }
        
        return helper(root, k);
    }
};