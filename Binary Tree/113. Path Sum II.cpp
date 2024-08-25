class Solution {
    
    vector<vector<int>> ans;
    vector<int> v;
    
    void helper(TreeNode* root, int tar) {
        if(root == NULL){
            // (tar < 0) wali condi include nhi kr skte 
            // as nodes ki value can be -ve 
            return;
        }
        
        tar -= root->val;
        v.push_back(root->val);
        if((root->left == NULL && root->right == NULL) &&  tar == 0){
            ans.push_back(v); 
            
            // ye wala step sbse jyada imp hai 
            // ki iss point oe bhi vector se element pop krna hai
            v.pop_back();
            return;
        }
        
        helper(root->left, tar);

        helper(root->right, tar);
        
        v.pop_back();
        return;
    }    
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int tar){
        if(root == NULL){
            return {};
        }
        helper(root, tar);
        
        return ans;
    }
};