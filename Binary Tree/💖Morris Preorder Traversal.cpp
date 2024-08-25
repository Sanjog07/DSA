class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // It's exactly same as Morris Inorder Traversal
        // bsss ek line ka change krna hai
        // isko bhi inorder wale tareeke se hoi sochna hai
        // jyada mt sochna
        // T.C = O(n) but here S.C = O(1)

        if(root == NULL){
            return {};
        }
        
        vector<int> ans;
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                ans.push_back(cur->val);
                cur = cur->right;
            }else{
                TreeNode* temp = cur->left;
                while(temp->right != NULL && temp->right != cur){
                    temp = temp->right;
                }
                
                if(temp->right == NULL){
                    temp->right = cur; // making of thread
                    ans.push_back(cur->val); // Sirf ye line yha pe aayegi ismei -> ye single change hai
                    cur = cur->left;
                }else{
                    temp->right = NULL; // cutting of thread
                    cur = cur->right;
                }
            }
        }
        
        return ans;        
    }
};