class Solution {
    
    int j = 0;
    TreeNode* build(vector<int>& in, vector<int>& post,int s,int e){
        if(s > e){
            return NULL;
        }
        
        int pvt = -1;
        for(int i=s; i<=e; i++){
            if(in[i] == post[j]){
                pvt = i;
                break;
            }
        }
        
        j++;
        
        // here we've applied reverse postorder traversal
        TreeNode* root = new TreeNode(in[pvt]);
        root->right = build(in, post, pvt+1, e);
        root->left = build(in, post, s, pvt-1);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post){
        int n = in.size();
        
        reverse(post.begin(), post.end());
        
        return build(in, post, 0, n-1);
    }
};