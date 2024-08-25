class Solution {
    
    vector<int> v;
    void storeOrder(TreeNode* root,vector<int> &v){
        if(root == NULL){
            return;
        }
        v.push_back(root->val);
        storeOrder(root->left,v);
        storeOrder(root->right,v);
        
        return;
    }
    
    int i = 0;
    void helper(TreeNode* root,int n,vector<int> &v){
        if(root == NULL || i >= n){
            return;
        }
        helper(root->left,n,v);
        //cout<<v[i]<<endl;
        root->val = v[i];
        i++;
        helper(root->right,n,v);
        
        return;
    }    
    
    
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL){
            return;
        }
        
        // Brute force
        //ās nodes swap ho gyi hai
        // so now it is a BT instead of BST
        // so now it is same as convert Binary Tree to BST
        
        // i.e hum ek nya BST construct nhi kr rhe 
        // as structure same rkhna hai to hum bus un nodes pe jaake
        // unki values change kr rhe hai
        // in inorder traversal
        
        vector<int> v;
        storeOrder(root,v);
        sort(v.begin() , v.end());
        helper(root,v.size(),v);
        
        return;
    }
};