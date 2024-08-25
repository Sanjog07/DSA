

void helper(TreeNode<int> * root, int x, int &ans){
    if(root == NULL){
        return;
    }

    if(root->val == x){
        ans = x;
        return;
    }else if(x < root->val){
        helper(root->left, x, ans);
    }else{
        ans = root->val;
        helper(root->right, x, ans);
    }
    
    return;
}

int floorInBST(TreeNode<int> * root, int x){
	int ans = INT_MAX;
    helper(root, x, ans);
	
  //ans == INT_MAX tb rh jayega when x < min val in BST
	return (ans == INT_MAX) ? -1 : ans;    
}