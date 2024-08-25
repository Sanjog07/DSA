
// https://www.youtube.com/watch?v=80Zug6D1_r4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=40

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // We'll do Morris Inorder Traversal
        // Iterative Approach 
        // T.C = O(n) but here S.C = O(1)
        // and this approach works on the principle of
        // Threaded Binary Tree
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
                    cur = cur->left;
                }else{
                    temp->right = NULL; // cutting of thread
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        
        return ans;
    }
};