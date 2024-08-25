


int helper(TreeNode<int> *root,int &ans){
    if(root == NULL){
        return 0;
    }
    int l = helper(root->left,ans);
    int r = helper(root->right,ans);
    ans = max(ans , root->data + l + r);
    
	return root->data + l + r;
}

int largestSubtreeSum(TreeNode<int> *root) {
	if(root == NULL){
        return 0;
    }
    int ans = INT_MIN;
    helper(root,ans);
    return ans;
}