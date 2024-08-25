class Solution{

    vector<vector<int>> ans;
    vector<int> v;
    
    void helper(Node *root, int sum){
        if(root == NULL){
            return;
        }
        
        sum -= root->key;
        v.push_back(root->key);
        if(sum == 0){
            ans.push_back(v);
            v.pop_back();
            return;
        }
        
        helper(root->left, sum);
        helper(root->right, sum);
        
        v.pop_back();
        return;
    }

    public:
    vector<vector<int>> printPaths(Node *root, int sum){
        if(root == NULL){
            return {};
        }
        
        helper(root, sum);
        
        return ans;
        
    }
};