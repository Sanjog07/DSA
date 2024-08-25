class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            vector<int> v;
            for(int i=0; i<n; i++){
                auto f = q.front();
                q.pop();
                
                v.push_back(f->val);
                
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }                
            }
            
            ans.push_back(v);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

// ON GFG
vector<int> reverseLevelOrder(Node *root){
        vector<int> ans;
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()){
            Node* level = q.front();
            ans.insert(ans.begin() , level->data);
            q.pop();
            
            if(level->right){
                q.push(level->right);
            }
            if(level->left){
                q.push(level->left);
            }
        }
        
        return ans;    
}