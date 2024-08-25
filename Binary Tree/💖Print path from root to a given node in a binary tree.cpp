vector<int> ans;

bool helper(TreeNode* root, int tar){
    if(root == NULL){
        return false;
    }

    ans.push_back(root->val);
    if(root->val == tar){
        return true;
    }
    if(helper(root->left, tar) || helper(root->right, tar)){
        return true;
    }

    ans.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* root, int tar) {
    ans.clear();
    if(root == NULL){
        return {};
    }

    helper(root, tar);

    return ans;
}