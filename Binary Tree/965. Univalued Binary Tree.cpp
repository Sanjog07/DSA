/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    bool check(TreeNode* root,int data){
        if(root == NULL){
            return true;
        }
        
        if(root->val == data && check(root->left, data) && check(root->right, data)){
            return true;
        }
        
        return false;
    }
    
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        int data = root->val;
        
        return check(root, data);
    }
};