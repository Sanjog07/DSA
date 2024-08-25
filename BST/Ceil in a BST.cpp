void helper(BinaryTreeNode<int> * root, int x, int &ans){
    if(root == NULL){
        return;
    }

    if(root->data == x){
        ans = x;
        return;
    }else if(x < root->data){
        ans = root->data;        
        helper(root->left, x, ans);
    }else{
        helper(root->right, x, ans);
    }
    
    return;
}

int findCeil(BinaryTreeNode<int> *root, int x){
	int ans = INT_MAX;
    helper(root, x, ans);

    //ans == INT_MAX tb rh jayega when x > max val in BST
    return (ans == INT_MAX) ? -1 : ans;    
}