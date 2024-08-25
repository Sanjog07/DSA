class Solution{
    vector<int> v;
    void storeOrder(Node* root,vector<int> &v){
        if(root == NULL){
            return;
        }
        v.push_back(root->data);
        storeOrder(root->left,v);
        storeOrder(root->right,v);
        
        return;
    }
    
    int i = 0;
    void helper(Node* root,int n,vector<int> &v){
        if(root == NULL || i >= n){
            return;
        }
        helper(root->left,n,v);
        //cout<<v[i]<<endl;
        root->data = v[i];
        i++;
        helper(root->right,n,v);
        
        return;
    }
    
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root){
        if(root == NULL){
            return NULL;
        }
        
        // i.e hum ek nya BST construct nhi kr rhe 
        // as structure same rkhna hai to hum bus un nodes pe jaake
        // unki values change kr rhe hai
        // in inorder traversal
        
        vector<int> v;
        storeOrder(root,v);
        sort(v.begin() , v.end());
        helper(root,v.size(),v);
        
        return root;
    }
};