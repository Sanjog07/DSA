class Solution {
    
    int ans = INT_MIN;
    
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }  
        
        int lans = helper(root->left);
        int rans = helper(root->right); 
        
        int value = root->val;
        
        int op1 = value + lans + rans;
        int op2 = value;        
        int op3 = value + lans;
        int op4 = value + rans;      
        
        ans = max({ans, op1, op2, op3, op4});
        
        return max({op2, op3, op4});
    }
    
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        } 
        
        helper(root);
        
        return ans;
    }
};