


// https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/

// Also see this Postorder one -> https://www.geeksforgeeks.org/construct-a-binary-search-tree-from-given-postorder/

// See only O(n) wali approach in both

class Solution {
    
    TreeNode* helper(int &i, vector<int>& pre,int min, int max,int n){
        if(i >= n){
            return NULL;
        }
        int data = pre[i];
        if(data > min && data < max){
            TreeNode* root = new TreeNode(data);
             
            i++;
            root->left = helper(i, pre, min, data, n);
            root->right = helper(i, pre, data, max, n);
            
            return root;
        }
        
        return NULL;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n = pre.size();
        
        int i = 0;
        TreeNode* ans = helper(i, pre, INT_MIN, INT_MAX, n);
        
        return ans;
    }
};






// class Solution {
    
//     TreeNode* insertInBst(TreeNode* root, int data){
//         if(root == NULL){
//             return new TreeNode(data);
//         }
        
//         if(data <= root->val){
//             root->left = insertInBst(root->left, data);
//         }else{
//             root->right = insertInBst(root->right, data);
//         }
        
//         return root;
//     } 
    
// public:
//     TreeNode* bstFromPreorder(vector<int>& pre) {
//         TreeNode* root = NULL;
//         for(int i=0; i<pre.size(); i++){
//             root = insertInBst(root, pre[i]);
//         }
        
//         return root;
//     }
// };