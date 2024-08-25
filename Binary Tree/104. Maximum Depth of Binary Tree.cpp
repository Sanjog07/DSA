class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL &&root->right == NULL){
            return 1;
        }
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return max(left, right) + 1;        
    }
};