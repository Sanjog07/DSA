class Solution {
    
    TreeNode* helper(TreeNode* root, int low, int high){
        if(root == NULL){
            return NULL;
        }
        
        TreeNode* lans = helper(root->left, low, high);
        TreeNode* rans = helper(root->right, low, high);
        
        int data = root->val;
        if((data < low || data > high)){
            if(lans == NULL && rans == NULL){
                return NULL;
            }else if(rans == NULL){
                return lans;
            }else if(lans == NULL){
                return rans;
            }  
            
            // jo iske agle wala case hai
            // i.e lans != NULL and rans != NULL vo exist hi nhi krega
            // i.e if left and right are included 
            // then definitely root is included, as it is a BST
        }
        
        
        
        // else{
        //     if(lans == NULL && rans == NULL){
        //         root->left = NULL;
        //         root->right = NULL;
        //     }else if(rans == NULL){
        //         root->left = lans;
        //         root->right = NULL;
        //     }else if(lans == NULL){
        //         root->left = NULL;
        //         root->right = rans;
        //     }else{
        //         root->left = lans;
        //         root->right = rans;                
        //     }         
        // }
        
        // To write above else statement in a shorter form
        root->left = lans;
        root->right = rans;

        return root;
    }
    
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return NULL;
        }
        
        TreeNode* ans = helper(root, low, high);
        
        return ans;
    }
};