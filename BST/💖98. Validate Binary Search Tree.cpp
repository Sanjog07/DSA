

class Solution {
    
    bool isBST(TreeNode* root, long max, long min){
        if(root == NULL){
            return true;
        }
        
        int value = root->val;
        
        bool l = isBST(root->left, value, min);
        bool r = isBST(root->right, max, value);
        
        if((value < max  && value > min) && l && r){
            return true;
        }
        
        return false;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        return isBST(root, LONG_MAX, LONG_MIN);
    }
};