typedef pair<bool, int> pii;

class Solution {
    
    pii helper(TreeNode* root){
        pii p;
        if(root == NULL){
            p.first = true;
            p.second = 0;
            
            return p;
        }
        
        pii l = helper(root->left);
        pii r = helper(root->right);
        
        p.second = max(l.second, r.second) + 1;
        if(abs(l.second - r.second) <= 1 && l.first && r.first){
            p.first = true;
        }else{
            p.first = false;
        }
        
        return p;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        pii ans = helper(root);
        
        return ans.first;
    }
};