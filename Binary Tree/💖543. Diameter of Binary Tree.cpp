typedef pair<int,int> pii;

class Solution {
    
    pii solve(TreeNode* root){
        pii p;
        if(root == NULL){
            p.first = 0;
            p.second = 0;
            return p;
        }
        
        pii l = solve(root->left);
        pii r = solve(root->right);
        
        int ans1 = l.second + r.second;
        int ans2 = l.first;
        int ans3 = r.first;
        
        p.first = max({ans1, ans2, ans3});
        p.second = max(l.second, r.second) + 1;
        
        return p;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        auto ans = solve(root);
        
        return ans.first;
    }
};