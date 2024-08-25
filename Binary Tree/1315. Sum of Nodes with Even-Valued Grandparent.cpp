


// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/discuss/1860868/C%2B%2B-oror-DFS-oror-EASY-TO-UNDERSTAND

// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/discuss/1863434/simple-c%2B%2B-solution-using-level-order-traversal

class Solution {
    
    int sum = 0;
    
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int data = root->val;
        if(data%2 == 0){
            if(root->left != NULL && root->left->left != NULL){
                sum += root->left->left->val;
            }
            if(root->left != NULL && root->left->right != NULL){
                sum += root->left->right->val;
            }
            if(root->right != NULL && root->right->left != NULL){
                sum += root->right->left->val;
            }
            if(root->right != NULL && root->right->right != NULL){
                sum += root->right->right->val;
            }            
        }
        
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        
        return sum;
    }
};