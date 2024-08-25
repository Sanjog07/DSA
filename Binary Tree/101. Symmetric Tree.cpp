
// Iterative Solu -> https://leetcode.com/problems/symmetric-tree/discuss/1872305/4-ms-C%2B%2B-Iterative-Solution-using-queue

class Solution {
    
    bool helper(TreeNode* l, TreeNode* r){
        if(l == NULL && r == NULL){
            return true;
        }        
        if(l == NULL || r == NULL){
            return false;
        }
        if(l->val == r->val && helper(l->right, r->left) && helper(l->left, r->right)){
            return true;
        }
        return false;
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return true;
        }
        
        return helper(root->left, root->right);
    }
};