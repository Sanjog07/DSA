class Solution {
    
    int j = 0;
    TreeNode* build(vector<int>& pre,vector<int>& in, int s, int e){
        
        if(s > e){
            return NULL;
        }
        
        int pvt = -1;
        for(int i=s; i<=e; i++){
            if(in[i] == pre[j]){
                pvt = i;
                break;
            }
        }
        
        j++;
        
        TreeNode* root = new TreeNode(in[pvt]);
        root->left = build(pre,in, s, pvt-1);
        root->right = build(pre,in, pvt+1, e);
        
        return root;
    }    
    
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        
        return build(pre, in, 0, n-1);
    }
};