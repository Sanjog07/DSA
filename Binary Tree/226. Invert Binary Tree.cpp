class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        
        swap(root->left, root->right);
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        TreeNode* swap = root->left;
        root->left = root->right;
        root->right = swap;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};