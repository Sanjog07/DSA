class custom{
    public:
    int min;
    int max;
    int cnt;
    bool isbst;
};

class Solution{

    int res = 1;

    custom helper(Node* root){
        if(root == NULL){
            return {INT_MAX, INT_MIN, 0, true};
        }
        if(root->left == NULL && root->right == NULL){
            return {root->data, root->data, 1, true};
        }

        custom lans = helper(root->left);
        custom rans = helper(root->right);

        custom ans;
        ans.cnt = lans.cnt + rans.cnt + 1;

        int val = root->data;
        if((val > lans.max && val < rans.min) && lans.isbst && rans.isbst){
            res = max(res, ans.cnt);
            ans.isbst = true;
        }else{
            ans.isbst = false;
        }

        ans.min = (root->left) ? lans.min : root->data;
        ans.max = (root->right) ? rans.max : root->data;

        return ans;
    }
    

    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root){
        if(root == NULL){
            return 0;
        }

        helper(root);

        return res;
    }
};