class Solution {
    
    TreeNode* prev = NULL;
    
public:
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        
        // bs hume ismei ek cheez ka dhyaan dena hai ki
        //as hume ek node ke dono left and right ko change krna hai
        // so uske original left and right ko store kr lena
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        
        root->left = NULL;
        if(prev != NULL){
            prev->right = root;
        }
        prev = root;
        
        flatten(l);
        flatten(r);
        
        return;
    }
};