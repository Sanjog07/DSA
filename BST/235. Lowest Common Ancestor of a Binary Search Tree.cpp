
class Solution {
    
    TreeNode* ans = NULL;
    
    void helper(TreeNode* root, int p, int q){
        int data = root->val;
        if(root == NULL || data == p || data == q){
            ans = root;
            return;
        }
        
        if((p < data && q > data) || (q < data && p > data)){
            ans = root;
            return;
        }else if(p < data && q < data){
            helper(root->left, p, q);
        }else{
            helper(root->right, p, q);
        }
        
        return;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        helper(root, p->val, q->val);
        
        return ans;
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL || root == p || root == q){
            return root;
        }
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if(l && r){
            return root;
        }
        
        return (l != NULL) ? l : r;
    }
};