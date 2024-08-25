class Solution {
    
    TreeNode* ans = NULL;
    
    void helper(TreeNode* root, int val) {
        if(root == NULL){
            return;
        }
        if(val == root->val){
            ans = root;
            return;
        }
        
        if(val < root->val){
            helper(root->left, val);
        }else{
            helper(root->right, val);
        }
        
        return;
    }    
    
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        } 
        
        helper(root, val);
        
        return ans;
    }
};