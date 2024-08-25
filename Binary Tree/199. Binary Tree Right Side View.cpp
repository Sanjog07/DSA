class Solution {
    
    vector<int> ans;
    int ml = INT_MIN;
    
    void helper(TreeNode* root, int cl){
        if(root == NULL){
            return;
        }
        
        if(cl > ml){
            ans.push_back(root->val);
            ml = cl;
        }
        
        helper(root->right, cl+1);
        helper(root->left, cl+1);
        
        return;
    }    
    
public:
    vector<int> rightSideView(TreeNode* root) {
        helper(root, 0);
        
        return ans;
    }
};



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        list<TreeNode*> q;
        q.push_back(root);
        
        while(!q.empty()){
            TreeNode* right = q.back();
            ans.push_back(right->val);
            
            int x = q.size();
            for(int i=0; i<x; i++){
                TreeNode* node = q.front();
                q.pop_front();
                
                if(node->left){
                    q.push_back(node->left);
                }
                if(node->right){
                    q.push_back(node->right);
                }
            }
        }
        return ans;        
    }
};

