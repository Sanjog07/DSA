 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int tar) {
        if(root == NULL){
            // (tar < 0) wali condi include nhi kr skte 
            // as nodes ki value can be -ve 
            return false;
        }
        
        tar -= root->val;
        if((root->left == NULL && root->right == NULL) &&  tar == 0){
            return true;
        }
        
        bool l = hasPathSum(root->left, tar);
        if(l) return true;
        bool r = hasPathSum(root->right, tar);
        if(r) return true;
        
        return false;
    }
};