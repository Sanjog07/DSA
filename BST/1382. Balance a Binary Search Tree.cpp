
class Solution {
    
    vector<int> v;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);

        return;
    }

    TreeNode* buildFromArray(int s,int e){
        if(s > e){
            return NULL;
        }

        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(v[mid]);

        root->left = buildFromArray(s,mid-1);
        root->right = buildFromArray(mid+1,e);

        return root;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        // we'll store inorder traversal of B.S.T in a vector
        // and then apply build from given array // by finding mid pt and all
        inorder(root);
        int n = v.size();

        TreeNode* ans = buildFromArray(0,n-1);

        return ans;    
    }
};