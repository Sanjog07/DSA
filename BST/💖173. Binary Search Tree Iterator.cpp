class BSTIterator {
    
    stack<TreeNode*> s;
    
public:
    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;
        while(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }
    }
    
    int next() {
        auto ans = s.top();
        s.pop();
        
        auto temp = ans;
        if(temp->right){
            temp = temp->right;
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
        }
        
        return ans->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
