class Solution {
    
    int sum = 0;
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        solve(root->right);
        
        sum += root->val;
        root->val = sum;
        
        solve(root->left);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        // we'll apply reverse inorder traversal
        solve(root);
        
        return root;
    }
};