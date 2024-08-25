
class Solution {
    
int solve(Node* root,int &res){
    if(root == NULL){
        return 0;
    }
    if (root->left == NULL && root->right == NULL){
       return root->data;
    }
    int l = solve(root->left,res);
    int r = solve(root->right,res);

    if(root->left == NULL){
        //res = max(res , r + root->data);
        return r + root->data;
    }
    if(root->right == NULL){
        //res = max(res , l + root->data);
        return l + root->data;
    }
    int temp = max(l,r) + root->data;
    int ans = l+r+root->data;
      
    res = max(res, ans);
    
    return temp;
    
}   
    
public:
    int maxPathSum(Node* root){
        if(root == NULL){
            return 0;
        }
        
        // leaf vo typical wali hi leaf hai
        // but ye bhi consider krna hai ->
        // Note: Here Leaf node is a node which is connected to exactly one different node.
        // see -> 5 N 6 -5 5
        
        int res = INT_MIN;
        int x = solve(root,res);
        
        if(root->left && root->right){
            return res;
        }
        
        return max(res, x);
    }
};
