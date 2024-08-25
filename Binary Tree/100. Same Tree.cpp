class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        
        // ye wali condi to root pe hi theek ho jayegi
        // if((p != NULL && q != NULL) && (p->val == q->val)){
        //     return true;
        // }
        
        if((p == NULL && q != NULL) || (q == NULL && p != NULL) || ((p != NULL && q != NULL) && (p->val != q->val))){
            return false;
        }
        
        bool lef = isSameTree(p->left, q->left);
        bool rig = isSameTree(p->right, q->right);
        
        if(lef && rig){
            return true;
        }
        
        return false;
    }
};