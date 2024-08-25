class Solution {
    
    int ans = -1;
    int ml = INT_MIN;
    void helper(TreeNode* root, int cl){
        if(root == NULL){
            return;
        }
        
        if(cl > ml){
            ans = root->val;
            ml = cl;
        }
        
        helper(root->left, cl+1);
        helper(root->right, cl+1);
        
        return;
    }
        
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL){
            return -1;
        }
        
        helper(root, 0);
        
        return ans;
    }
};