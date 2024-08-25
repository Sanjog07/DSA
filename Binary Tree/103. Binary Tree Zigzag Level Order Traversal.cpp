
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        
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
            
            if(level%2 == 0){
                reverse(v.begin(), v.end());
            }
            ans.push_back(v);
            
            level++;
        }
        
        return ans;
    }
};