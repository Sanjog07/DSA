class Solution {
    
    TreeNode* prev = NULL;
    TreeNode* head;
    
    void helper(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        helper(root->left);
        if(prev == NULL){
            head = root;
        }else{
            prev->right = root;
            root->left = NULL;
        }
        
        prev = root;
        helper(root->right);
        
        return;
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        helper(root);
        
        return head;
    }
};